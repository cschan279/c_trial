#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

//#include "can_packing.h"
//#include "can_pack.h"
//#include "print_binary.h"
//#include "can_io.h"

/*
void print_string(char *str, int *s){
    char ifr_name[16];
    strcpy(ifr_name, str );
    printf("<%s>\n", ifr_name);
    *s = 1;
}
*/

/*
int test_can_id(){
    struct can_pack pack;
    struct can_pack *packp;
    packp = &pack;
    pack.prio = 0x5;
    pack.pf = 0x81;
    pack.ps = 0x81;
    pack.sa = 0x81;
    printb_c(pack.prio);
    printb_c(pack.pf);
    printb_c(pack.ps);
    printb_c(pack.sa);
    printf("\n");
    printf("Encode: ");
    int res = can_id_encode(packp);
    
    if (res != 0) {
        printf("Failed\n");
        printb(pack.id);
    } else {
        printf("Success\n");
        printb(pack.id);
    }
    
    printf("decode:\n");
    struct can_pack pack2;
    pack2.id = 0x14818181;
    can_id_decode(&pack2);
    printb(pack2.prio);
    printb(pack2.pf);
    printb(pack2.ps);
    printb(pack2.sa);
    printf("\n");

    return 0;
}
*/

void binarystring(unsigned var, char *str, unsigned len){
    unsigned mask, pos;
    for (unsigned i = 0; i < len; i++){
        mask = 1 << i;
        pos = len - 1 - i;
        str[pos] = (var & mask) ? '1' : '0';
    }
}

int main(int argc, char **argv)
{
    //test_can_id();
    //char var = 0xFF;
    //print_binary((unsigned char)var, 16);
    //short v1 = 0x3333;
    //char s1[16] = {0};
    //printf("%ld\n", sizeof(s1));
    //binarystring((unsigned)v1, s1, 16);
    //printf("{%s}", s1);
    //printf("\n");
    //printf("%ld\n", sizeof(s1));
    float f0 = 0.0;
    float f1 = 700.0;
    
    char dat0[8] = {0,0,0,0,0x00,0x00, 0x00, 0x00};
    char dat1[8] = {0,0,0,0,0x00,0x00, 0x2F, 0x44}; //{0,0,0,0,0x44,0x2F, 0x00, 0x00};
    
    memcpy(&f0, dat1+4, 4);
    memcpy(dat0+4, &f1, 4);
    for (int i=0; i<8;i++) printf("%X ", dat0[i]);
    printf("== %f \n", f0);
    
    
    return 0;
}
