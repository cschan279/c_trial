#ifndef ZLAN6842_H
#define ZLAN6842_H

#include <time.h>
#include <mutex>
#include <chrono>

#include <stdio.h>
#include <stdexcept>
#include <vector>
#include <modbus/modbus.h>

#define ZLAN_SERVER_PORT            502
#define ZLAN_DEVICE_ID              1
#define MODBUS_TIMEOUT_SEC          0
#define MODBUS_TIMEOUT_USEC         1000000
#define MODBUS_DEBUG                OFF

void ctxConfig(modbus_t *ctx);
void ctxClose(modbus_t *ctx);

class ZLAN6842
{
public:
    ZLAN6842(__uint8_t devID);
    __uint8_t devID;
    char dev_ip[20];
    
    time_t last_update;
    __uint8_t input_bit[8], output_bit[8], output_bit_buf[8];
    __uint16_t input_byte[8];
    
    
    int get_IOs();
    int set_DOs();
    void print_IOs();


    
    

private:
    std::timed_mutex mutex;
};
#endif // ZLAN6842_H
