#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include <net/if.h>
#include <sys/ioctl.h>
#include <sys/socket.h>

#include <linux/can.h>
#include <linux/can/raw.h>

#include "can_io.h"

int can_socket(char *io_name, int *s)
{
	struct sockaddr_can addr;
	struct ifreq ifr;
	struct can_frame frame;

	//PF_CAN=29; SOCK_RAW = 3; CAN_RAW=1
	if ((*s = socket(PF_CAN, SOCK_RAW, CAN_RAW)) < 0) {
		perror("Socket");
		return 1;
	}

	strcpy(ifr.ifr_name, io_name );
	ioctl(*s, SIOCGIFINDEX, &ifr);

	memset(&addr, 0, sizeof(addr));
	addr.can_family = AF_CAN;
	addr.can_ifindex = ifr.ifr_ifindex;

	if (bind(*s, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
		perror("Bind");
		return 1;
	}
	return 0;
}

int can_send(int s, int cid, int dlc, char *dat){
	struct can_frame frame;
	frame.can_id = cid;
	frame.can_dlc = dlc;
	memcpy(frame.data, dat, dlc*sizeof(char));
	if (write(s, &frame, sizeof(struct can_frame)) != sizeof(struct can_frame)) {
		perror("Write");
		return 1;
	}
	return 0;
}

int can_recv(int s, int *cid, int *dlc, char *dat){
	struct can_frame frame;
	int nbytes = read(s, &frame, sizeof(struct can_frame));

 	if (nbytes < 0) {
		perror("Read");
		return 1;
	}
	*cid = frame.can_id;
	*dlc = frame.can_dlc;
	memcpy(dat, frame.data, frame.can_dlc*sizeof(char));
	return 0;
}

void print_hex_array(char *hex_array, int length) {
	for (int i=0; i < length; i++) 
		printf("%02X", hex_array[i]);
	printf("\r\n");
}