#include <stdio.h>
#include <stdlib.h>

#include "print_binary.h"

void print_binary(unsigned var, __uint8_t bit){
    printf("%5d 0x%04x ", var, var);
    for (unsigned i = 1 << (bit - 1); i > 0; i = i / 2)
        (var & i) ? printf("1") : printf("0");
    printf("\n");
}