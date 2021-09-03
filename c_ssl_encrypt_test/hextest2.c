#include <stdio.h>
#include <string.h>
#include "hex_conv.h"


int main (int argc, unsigned char **argv[])
{
    //unsigned int c_len = 128;
    //unsigned char text[c_len];
    
    
    unsigned char *input = (unsigned char *)argv[1];
    unsigned int c_len = (unsigned int) strlen(input);
    unsigned char text[c_len];

    int fail = hex2str(input, text, c_len);
    printf("\n%zu: %s\n",strlen(text), text);
    
}