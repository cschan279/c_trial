#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void printb(int var){
    printf("%010d 0x%08x ", var, var);
    unsigned i;
    for (i = 1 << 31; i > 0; i = i / 2)
        (var & i) ? printf("1") : printf("0");
    printf("\n");
}

void printb_c(__uint8_t var){
    printf("%03d 0x%02x ", var, var);
    unsigned i;
    for (i = 1 << 7; i > 0; i = i / 2)
        (var & i) ? printf("1") : printf("0");
    printf("\n");
}



int can_id_encode(int* can_id, __uint8_t prio, __uint8_t pf, __uint8_t ps, __uint8_t sa){
    *can_id = 0;

    if (prio > 0x7) return -1;
    //if (pf != 0x73 && pf != 0x74) return -2;

    *can_id = (*can_id | prio) << 10;
    *can_id = (*can_id | pf) << 8;
    *can_id = (*can_id | ps) << 8;
    *can_id = (*can_id | sa);

    return 0;
}

int can_id_decode(int can_id, __uint8_t* prio, __uint8_t* pf, __uint8_t* ps, __uint8_t* sa){
    int buf;
    *prio = (can_id >> 26) & 0x7;
    *pf = (can_id >> 16) & 0xFF;
    *ps = (can_id >> 8) & 0xFF;
    *sa = (can_id) & 0xFF;
    return 0;
}
