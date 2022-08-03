#include "zlan6842.h"


void ctxConfig(modbus_t *ctx){
    uint32_t tv_sec, tv_usec;
    modbus_set_slave(ctx, ZLAN_DEVICE_ID);
    modbus_set_debug(ctx, MODBUS_DEBUG);

    tv_sec = MODBUS_TIMEOUT_SEC;
    tv_usec = MODBUS_TIMEOUT_USEC;
    modbus_get_byte_timeout(ctx, &tv_sec, &tv_usec);
    tv_sec = MODBUS_TIMEOUT_SEC;
    tv_usec = MODBUS_TIMEOUT_USEC;
    modbus_set_response_timeout(ctx, tv_sec, tv_usec);
}
void ctxClose(modbus_t *ctx){
    modbus_close(ctx);
    modbus_free(ctx);
}

ZLAN6842::ZLAN6842(__uint8_t devID): devID(devID)
{
    sprintf(this->dev_ip, "192.168.1.%d", devID);
}

int ZLAN6842::get_IOs(){
    // connect to device
    modbus_t *ctx = modbus_new_tcp(this->dev_ip, ZLAN_SERVER_PORT);
    ctxConfig(ctx);
    if (modbus_connect(ctx) != 0) {
        fprintf(stderr, "Connection failed: %s\n", modbus_strerror(errno));
        modbus_free(ctx);
        return -1;
    }
    //get AIs
    __uint16_t bytes[8];
    if(modbus_read_input_registers(ctx, 0, 8, bytes)<0){
        fprintf(stderr, "Error in reading AI (%s)\n", modbus_strerror(errno));
        ctxClose(ctx);
        return -1;
    }
    for (unsigned i=0;i<8;i++){
        this->input_byte[i] = bytes[i];
    }
    
    //get DIs
    __uint8_t bits[8];
    if(modbus_read_input_bits(ctx, 0, 8, bits)<0){
        fprintf(stderr, "Error in reading DI (%s)\n", modbus_strerror(errno));
        ctxClose(ctx);
        return -1;
    }
    for (unsigned i=0;i<8;i++){
        this->input_bit[i] = bits[i];
    }
    
    //get DOs
    if(modbus_read_bits(ctx, 0, 8, bits)<0){
        fprintf(stderr, "Error in reading DO (%s)\n", modbus_strerror(errno));
        ctxClose(ctx);
        return -1;
    }
    for (unsigned i=0;i<8;i++){
        this->output_bit[i] = bits[i];
    }
    
    
    
    this->last_update = time(NULL);
    
    ctxClose(ctx);
    return 0;
}



int ZLAN6842::set_DOs(){
    // connect to device
    modbus_t *ctx = modbus_new_tcp(this->dev_ip, ZLAN_SERVER_PORT);
    ctxConfig(ctx);
    if (modbus_connect(ctx) != 0) {
        fprintf(stderr, "Connection failed: %s\n", modbus_strerror(errno));
        modbus_free(ctx);
        return -1;
    }
    //set DOs
    if(modbus_write_bits(ctx, 16, 8, this->output_bit_buf)<0){
        fprintf(stderr, "Error in writing DO (%s)\n", modbus_strerror(errno));
        ctxClose(ctx);
        return -1;
    }
    ctxClose(ctx);
    return 0;
}


void ZLAN6842::print_IOs(){
    //DIs
    for (unsigned i=0;i<8;i++) printf("%d ", this->input_bit[i]);
    printf("\n");
    //DOs
    for (unsigned i=0;i<8;i++) printf("%d ", this->output_bit[i]);
    printf("\n");
    //AIs
    for (unsigned i=0;i<8;i++) printf("%4d ", this->input_byte[i]);
    printf("\n");
}

