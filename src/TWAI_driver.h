#ifndef TWAI_DRIVER_H
#define TWAI_DRIVER_H

#include <Arduino.h>
#include <driver/gpio.h>
#include <driver/twai.h>

#define GPIO_CANBUS_TX GPIO_NUM_4
#define GPIO_CANBUS_RX GPIO_NUM_5

class TWAI_Interface{
    private:
    twai_message_t CanTxMessage;
    twai_message_t CanRxMessage;
    uint8_t TXdatactrl = 0;
    public:
    TWAI_Interface (uint16_t TWAI_BAUD);
    void TXpacketBegin (uint16_t TWAITX_ID,uint8_t TWAITX_EXTD_EN);
    void TXpacketLoad (uint8_t TWAITX_DATA);
    uint8_t TXpackettransmit ();
    
    uint32_t RXpacketBegin();
    uint8_t RXpacketRead(uint8_t RX_INDEX);
    uint8_t RXgetDLC();
};

#endif