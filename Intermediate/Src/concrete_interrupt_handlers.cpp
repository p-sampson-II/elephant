#include "concrete_interrupt_handlers.h"

i2sObject::i2sObject() : isBufferEmpty(true),hi2s(nullptr) {}

i2sObject::i2sObject(I2S_HandleTypeDef& hi2s) : isBufferEmpty(true), hi2s(&hi2s) {}

i2sObject& i2sObject::operator=(const i2sObject& other) {
    this->hi2s = other.hi2s;
}

void i2sObject::irq(){
    this->isBufferEmpty = true;
}

bool i2sObject::bufferIsEmpty() {
    return this->isBufferEmpty;
}

void i2sObject::resetIsBufferEmpty() {
    isBufferEmpty = false;
}