#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
#include <unistd.h>
#include <time.h>

unsigned interval = 5*60; 

void until_next_tick(time_t *last_tick){
    time_t now = time(NULL);
    time_t next_tick = now / interval * interval + interval;
    time_t diff = next_tick - now;
    usleep(diff * 1000 * 1000);
    *last_tick = next_tick;
}
void print_current_time(char *str){
    time_t raw = time(NULL);
    struct tm *curr = localtime(&raw);
    sprintf(str, "%04d/%02d/%02d %02d:%02d:%02d", 
        curr->tm_year+1900, curr->tm_mon+1, curr->tm_mday, 
        curr->tm_hour, curr->tm_min, curr->tm_sec);
}

int main(int argc, char **argv)
{
    time_t last_tick = time(NULL);
    char str[30];
    while (1) {
        print_current_time(str);
        printf("%s\n", str);
        until_next_tick(&last_tick);
    }
    return 0;
}
