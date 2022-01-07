#include <ctime>
#include <iostream>
#include <chrono>
#include <thread>
extern "C" {
    #include <unistd.h>
}

class ClockTick{
public:
    ClockTick(__uint8_t m_interval);
    void tickString(char *str);
    void nowString(char *str);
    int tick();
private:
    __uint64_t s_interval;
    std::time_t t;
};

ClockTick::ClockTick(__uint8_t m_interval){
    this->s_interval = m_interval * 60;
    this->t = (std::time(0) / this->s_interval) * this->s_interval;
}
int ClockTick::tick(){
    std::time_t t = (std::time(0) / this->s_interval) * this->s_interval;
    __uint64_t result = t-this->t;
    this->t = t;
    return result;
}

void ClockTick::tickString(char *str){
    std::tm* now = std::localtime(&(this->t));
    sprintf(str, "[%04d/%02d/%02d %02d:%02d:%02d]", 
        (now->tm_year + 1900), (now->tm_mon + 1), 
        now->tm_mday, now->tm_hour, now->tm_min, now->tm_sec);
}

void ClockTick::nowString(char *str){
    std::time_t t = std::time(0);
    std::tm* now = std::localtime(&t);
    sprintf(str, "[%04d/%02d/%02d %02d:%02d:%02d]", 
        (now->tm_year + 1900), (now->tm_mon + 1), 
        now->tm_mday, now->tm_hour, now->tm_min, now->tm_sec);
}

int main() {
    ClockTick cktk = ClockTick(2);
    while (true) {
        char t[30], n[30];
        int tick = cktk.tick();
        cktk.tickString(t);
        cktk.nowString(n);
        std::cout << t << n << tick << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }
    
    /*
    std::cout << (now->tm_year + 1900) << '-' 
         << (now->tm_mon + 1) << '-'
         <<  now->tm_mday << ' '
         <<  now->tm_hour << ':'
         <<  now->tm_min << ':'
         <<  now->tm_sec
         << "\n";
    */
}
