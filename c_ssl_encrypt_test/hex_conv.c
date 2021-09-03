#include <stdio.h>
#include <string.h>

int hex2str (unsigned char *hex, unsigned char *str, long unsigned int c_len)
{
    long unsigned int len = strlen(hex);
    if (len > (c_len*2))
    {
        printf("Input length(%zu) is over", len);
        return 1;
    }
    
    for(int i=0; i<len; i+=2)
    {
        unsigned char c;
        unsigned char buf[2];
        memcpy(buf,&hex[i], 2);
        sscanf(buf, "%2hhx", &c);
        unsigned int ind = i/2;
        str[ind] = c;
    }
    return 0;
}