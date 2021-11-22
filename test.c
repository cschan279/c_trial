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

int test_can_id(){
    __uint8_t prio = 0x5;
    __uint8_t pf = 0x81;
    __uint8_t ps = 0x81;
    __uint8_t sa = 0x81;
    printb_c(prio);
    printb_c(pf);
    printb_c(ps);
    printb_c(sa);
    printf("\n");
    int cid = 0;
    int res = can_id_encode(&cid, prio, pf, ps, sa);
    printf(">>%X\n", cid);
    if (res != 0) {
        printf("Failed");
        return -1;
    }
    printb(cid);

    printf("decode:\n");
    __uint8_t prio2 = 0;
    __uint8_t pf2 = 0;
    __uint8_t ps2 = 0;
    __uint8_t sa2 = 0;
    can_id_decode(cid, &prio2, &pf2, &ps2, &sa2);
    printb(prio2);
    printb(pf2);
    printb(ps2);
    printb(sa2);
    printf("\n");

    return 0;
}


int main(int argc, char **argv)
{
    /*
    int s = 0;
    print_string("hello", &s);
    printf("result: %d\n", s);
    printf("%X\n", -1);
    */
    /*
    unsigned char var = 0x81;
    printb(var);
    */
    /*
    char a = 0x81;
    __uint8_t b = (__uint8_t)a;
    printf("%x %x\n", a, b);
    */
    return test_can_id();
    

    return 0;
}