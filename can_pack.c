#include <stdio.h>
#include <stdlib.h>

#include "can_pack.h"

int assert_can_pack(struct can_pack pack){
    if (pack.prio > 0x7) return -1;
    //if (pack.pf != 0x73 && pack.pf != 0x74) return -2;
    return 0;
}

int can_id_encode(struct can_pack *pack){
    int cid = 0;
    
    cid = (cid | pack->prio) << 10;
    cid = (cid | pack->pf) << 8;
    cid = (cid | pack->ps) << 8;
    cid = (cid | pack->sa);
    pack->id = cid;
    return assert_can_pack(*pack);
}

int can_id_decode(struct can_pack *pack){
    pack->prio = (pack->id >> 26) & 0x7;
    pack->pf = (pack->id >> 16) & 0xFF;
    pack->ps = (pack->id >> 8) & 0xFF;
    pack->sa = (pack->id) & 0xFF;
    return assert_can_pack(*pack);
}

void printb(int var){
    printf("%010d 0x%08x ", var, var);
    for (unsigned i = 1 << 31; i > 0; i = i / 2)
        (var & i) ? printf("1") : printf("0");
    printf("\n");
}

void printb_c(__uint8_t var){
    printf("%03d 0x%02x ", var, var);
    for (unsigned i = 1 << 7; i > 0; i = i / 2)
        (var & i) ? printf("1") : printf("0");
    printf("\n");
}