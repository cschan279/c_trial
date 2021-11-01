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

#ifndef _DUMMY_DATA_
#define _DUMMY_DATA_
int dummy_cid = 0x555;
int dummy_dlc = 8;
char dummy_data[8] = {0x01, 0x10, 0x23, 0x32, 0x45, 0x54, 0x67, 0x76};
#endif