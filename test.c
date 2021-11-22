#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

//#include "can_packing.h"
#include "can_pack.h"

void print_string(char *str, int *s){
    char ifr_name[16];
    strcpy(ifr_name, str );
    printf("<%s>\n", ifr_name);
    *s = 1;
}


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


int main(int argc, char **argv)
{
    test_can_id();
    
    

    return 0;
}