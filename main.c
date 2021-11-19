#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "can_io.h"


int main(int argc, char **argv)
{
    if (argc != 3) {
        printf("example:\n");
        printf(">main.o recv can0\n");
        printf(">main.o tran both\n");
        return 1;
    }

    printf("%s %s %s\n", argv[0], argv[1], argv[2]);

    int s0, s1;
    if (!strcmp(argv[2], "both")) {
        if (can_socket("vcan0", &s0)) {
            perror("Start 0");
            return 1;
        }
        if (can_socket("vcan1", &s1)){
            perror("Start 1");
            return 1;
        }
    } else {
        if (can_socket(argv[2], &s0)) {
            perror("Start 0");
            return 1;
        }
    }

    printf("Initialized: %d %d\n", s0, s1);

    if (!strcmp(argv[1], "tran")) {
        printf("Transmit\n");
        char data0[8] = {0x01, 0x10, 0x23, 0x32, 0x45, 0x54, 0x67, 0x76};
        if (can_send(s0, 0x1FFFFFFF, 8, data0)) return 1;
        if (!strcmp(argv[2], "both")) {
            char data1[8] = {0x17, 0x26, 0x35, 0x44, 0x53, 0x62, 0x71, 0x80};
            if (can_send(s1, 0x1FFFFFFF, 8, data1)) return 1;
        } 
    } else if (!strcmp(argv[1], "recv")) {
        printf("Received:\n");
        int cid, dlc;
        char dat[8];
        if (can_recv(s0, &cid, &dlc, dat)) return 1;
        printf("0x%03X [%d] ",cid, dlc);
        print_hex_array(dat, dlc);
        if (!strcmp(argv[2], "both")) {
            if (can_recv(s1, &cid, &dlc, dat)) return 1;
            printf("0x%03X [%d] ",cid, dlc);
            print_hex_array(dat, dlc);
        }
    } else {
        printf("Invalid command: <%s>\n", argv[1]);
    }

    
    /*
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
    */
	return 0;
}
