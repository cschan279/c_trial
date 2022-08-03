#include <stdio.h>

#include "zlan6842.h"




int main() {
    ZLAN6842 *zio = new ZLAN6842((__uint8_t)254);
    __uint8_t flag = 1;
    for (unsigned x=0;x<4;x++){
        for (unsigned i=0;i<8;i++){
            if (zio->get_IOs()) return -1;
            zio->print_IOs();
            zio->output_bit_buf[i] = flag;
            if (zio->set_DOs()) return -1;
        }
        flag = (!flag);
    }

}
