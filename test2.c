#include <sys/time.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h>


void sleep_to_next(struct timeval *tick_time, unsigned s_interval){
    struct timeval now;
    gettimeofday(&now, NULL);
    tick_time->tv_usec = 0;
    tick_time->tv_sec = now.tv_sec / s_interval * s_interval + s_interval;
    __uint64_t diff = (tick_time->tv_sec - now.tv_sec) * 1000000 - now.tv_usec;
    usleep(diff);
}

void tick_str(struct timeval tick_time, char *str){
    struct tm *curr = localtime(&(tick_time.tv_sec));
    sprintf(str, "[%04d/%02d/%02d %02d:%02d:%02d.%06ld]", 
        curr->tm_year+1900, curr->tm_mon+1, curr->tm_mday, 
        curr->tm_hour, curr->tm_min, curr->tm_sec, tick_time.tv_usec);
}

void until_next_tick(struct timeval *last_tick, unsigned s_interval){
    struct timeval now;
    gettimeofday(&now, NULL);
    struct tm *curr = localtime(&now.tv_sec);
    printf("[%04d/%02d/%02d %02d:%02d:%02d.%06ld]\t", 
        curr->tm_year+1900, curr->tm_mon+1, curr->tm_mday, 
        curr->tm_hour, curr->tm_min, curr->tm_sec, now.tv_usec);
    last_tick->tv_usec = 0;
    last_tick->tv_sec = now.tv_sec / s_interval * s_interval + s_interval;
    __uint64_t diff = (last_tick->tv_sec - now.tv_sec) * 1000000 - now.tv_usec;
    printf("%ld\t", diff);
    struct tm *next = localtime(&(last_tick->tv_sec));
    printf("[%04d/%02d/%02d %02d:%02d:%02d.%06ld]\n", 
        next->tm_year+1900, next->tm_mon+1, next->tm_mday, 
        next->tm_hour, next->tm_min, next->tm_sec, last_tick->tv_usec);
    
    usleep(diff);
}
void current_time_str(char *str){
    time_t raw = time(NULL);
    struct tm *curr = localtime(&raw);
    sprintf(str, "%04d/%02d/%02d %02d:%02d:%02d", 
        curr->tm_year+1900, curr->tm_mon+1, curr->tm_mday, 
        curr->tm_hour, curr->tm_min, curr->tm_sec);
}
int main() {
    unsigned m_interval = 1;
    struct timeval last_tick;
    gettimeofday(&last_tick, NULL);
    char str[30];
    while (1) {
        current_time_str(str);
        printf("%s\n", str);
        until_next_tick(&last_tick, 20);
    }
    return 0;
}