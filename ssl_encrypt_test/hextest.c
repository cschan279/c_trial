#include <stdio.h>
#include <string.h>

int main (int argc, unsigned char **argv[])
{
    unsigned int limit = 256;
    unsigned char text[limit/2];
    
    
    unsigned char *input = (unsigned char *)argv[1];
    long unsigned int len = strlen(input);
    printf("%zu: %s\n", len, input);
    
    for(int i=0; i<len; i+=2)
    {
        unsigned char c;
        unsigned char buf[2];
        memcpy(buf,&input[i], 2);
        sscanf(buf, "%2hhx", &c);
        unsigned int ind = i/2;
        text[ind] = c;
    }
    printf("\n%zu: %s\n",strlen(text), text);
    
}