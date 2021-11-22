#include <stdio.h>

void printb(int var);

void printb_c(char var);

int can_id_encode(int* can_id, __uint8_t prio, __uint8_t pf, __uint8_t ps, __uint8_t sa);
int can_id_decode(int can_id, __uint8_t* prio, __uint8_t* pf, __uint8_t* ps, __uint8_t* sa);