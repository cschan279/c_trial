#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>


void print_string(char *str, int *s){
    char ifr_name[16];
    strcpy(ifr_name, str );
    printf("<%s>\n", ifr_name);
    *s = 1;
}


int main(int argc, char **argv)
{
    int s = 0;
    print_string("hello", &s);
    printf("result: %d\n", s);
}