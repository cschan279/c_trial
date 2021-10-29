#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include <net/if.h>
#include <sys/ioctl.h>
#include <sys/socket.h>

#include <linux/can.h>
#include <linux/can/raw.h>

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

int main(int argc, char **argv)
{
	int s0, s1;
	if (can_socket("vcan0", &s0)) {
		perror("Start 0");
		return 1;
	}
	if (can_socket("vcan1", &s1)){
		perror("Start 1");
		return 1;
	}

	printf("can s: %d, %d\n", s0, s1);
	
	char data0[8] = {0x01, 0x10, 0x23, 0x32, 0x45, 0x54, 0x67, 0x76};
	char data1[8] = {0x17, 0x26, 0x35, 0x44, 0x53, 0x62, 0x71, 0x80};
	can_send(s0, 0x555, 8, data0);
	can_send(s1, 0x666, 8, data1);
	

	if (close(s0) < 0) {
		perror("Close");
		return 1;
	}
	if (close(s1) < 0) {
		perror("Close");
		return 1;
	}

	return 0;
}