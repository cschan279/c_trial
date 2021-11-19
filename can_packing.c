#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void printb(int var){
    printf("%d %x ", var, var);
    unsigned i;
    for (i = 1 << 31; i > 0; i = i / 2)
        (var & i) ? printf("1") : printf("0");
    printf("\n");
}



int can_id_encode(int prio, int pf, int ps, int sa){
    int can_id = 0;
    if (prio > 0x7) return -1;
    //if (pf != 0x73 && pf != 0x74) return -2;
    can_id = (can_id | (prio & 0x7)) << 10;
    can_id = (can_id | (pf & 0xFF)) << 8;
    can_id = (can_id | (ps & 0xFF)) << 8;
    can_id = (can_id | (sa & 0xFF));

    return can_id;
}