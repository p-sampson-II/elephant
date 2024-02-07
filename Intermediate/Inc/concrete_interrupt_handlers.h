#pragma once
#include "interrupt_handler.h"
#include "stm32f4xx_hal.h"

class i2sObject : public InterruptHandler {
public:

    i2sObject();
    i2sObject(I2S_HandleTypeDef& hi2s);

    void irq();
    bool bufferIsEmpty();
    void resetIsBufferEmpty();

    void setI2s(I2S_HandleTypeDef& hi2s) { this->hi2s = &hi2s; }
    I2S_HandleTypeDef& getI2s() { return *(this->hi2s); } // Keep an eye on this line

    i2sObject& operator=(const i2sObject& other);

    private:
    bool isBufferEmpty;
    I2S_HandleTypeDef* hi2s;
};