#include <stdio.h>
#include <stdlib.h>

#define ARRAY_SIZE 50

struct can_pack{
    int id;
    __uint8_t prio;
    __uint8_t pf;
    __uint8_t ps;
    __uint8_t sa;
    __uint8_t data[8];
};

int assert_can_pack(struct can_pack pack);

int can_id_encode(struct can_pack *pack);
int can_id_decode(struct can_pack *pack);

void printb(int var);
void printb_c(__uint8_t var);