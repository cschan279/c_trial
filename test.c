#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "can_packing.h"

void print_string(char *str, int *s){
    char ifr_name[16];
    strcpy(ifr_name, str );
    printf("<%s>\n", ifr_name);
    *s = 1;
}




int main(int argc, char **argv)
{
    //int s = 0;
    //print_string("hello", &s);
    //printf("result: %d\n", s);
    //printf("%X\n", -1);
    int prio = 0x5;
    int pf = 0x81;
    int ps = 0x81;
    int sa = 0x81;
    printb(prio);
    printb(pf);
    printb(ps);
    printb(sa);
    printf("\n");
    int cid = can_id_encode(prio, pf, ps, sa);
    printf(">>%X\n", cid);
    if (cid < 0) {
        printf("Failed");
        return -1;
    }
    printb(cid);
    return 0;
    
    
    
}