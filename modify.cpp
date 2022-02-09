#include "modify.h"


void modify_ts2(){
    time_t t = time(NULL);
    var::ts2 = {t,  0, 1,  2.1, 2.2};
}

void modify_ts(TestStruct *ts){
    time_t t = time(NULL);
    *ts = {t,  2, 1,  1.1, 1.2};
}

void print_ts(TestStruct *ts){
    TestStruct temp = *ts;
    printf("[%012ld]\t", temp.t);
    printf("%d\t%d\t%.1f\t%.1f\n", temp.a, temp.b, temp.c, temp.d);
}