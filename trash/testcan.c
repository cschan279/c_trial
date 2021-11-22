#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "can_io.h"


char get_option(){
    char c = '0';
    printf("Choose:\n r.Receive\n s.Send\n q.Quit\n");
    while ( (c = getchar()) == '\n' || c == EOF ) { }
    if (c != 'r' && c != 's' && c != 'q') {
        printf("Invalid option: <%c>\n", c);
        return 'e';
    } else return c;
}

int main(int argc, char **argv) {
    if (argc != 2) {
        printf("example:\n");
        printf(">testcan.o can0\n");
        return 1;
    }
    char *port = (char*) argv[1];
    printf("Testing on %s\n", port);
    int s;

    if (can_socket(port, &s)) {
        perror("Start port");
        return 1;
    }
    
    set_timeout(s, 1, 50000);

    char option = 'e';
    while (option != 'q') {
        option = get_option();
        if (option == 'r') {
            int cid, dlc;
            char dat[8];
            if (can_recv(s, &cid, &dlc, dat)) return 1;
            printf("0x%03X [%d] ",cid, dlc);
            print_hex_array(dat, dlc);
        } else if (option == 's') {
            char data[8] = {0x01, 0x10, 0x23, 0x32, 0x45, 0x54, 0x67, 0x76};
            if (can_send(s, 0x555, 8, data)) return 1;
        } else if (option == 'q') return 0;
    }
    return 0;
}