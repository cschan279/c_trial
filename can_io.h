#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include <net/if.h>
#include <sys/ioctl.h>
#include <sys/socket.h>

#include <sys/select.h>

#include <linux/can.h>
#include <linux/can/raw.h>

int can_socket(char *io_name, int *s);
void set_timeout(int s, long sec, long usec);
int can_send(int s, int cid, int dlc, char *dat);
int can_recv(int s, int *cid, int *dlc, char *dat);
void print_hex_array(char *hex_array, int length);

