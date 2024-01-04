#pragma once
#include <array.h>
#include "sys_const.h"

class AudioSystem {
public:
    AudioSystem(I2C_HandleTypeDef& hi2c,
                DMA_HandleTypeDef& hdma_spi_tx,
                I2S_HandleTypeDef& hi2s,
                array<uint16_t,audio_buffer_size>& sampleBuffer);

    AudioSystem(I2C_HandleTypeDef& hi2c,
                DMA_HandleTypeDef& hdma_spi_tx,
                I2S_HandleTypeDef& hi2s);

    AudioSystem();

    void play();
    void setBuffer(std::array<uint16_t,audio_buffer_size>& sampleBuffer);

private:
    inline bool isBufferSet();

    std::array<uint16_t,audio_buffer_size>* sampleBuffer;

    I2S_HandleTypeDef* hi2s;
    DMA_HandleTypeDef* hdma_spi_tx;
    I2C_HandleTypeDef* hi2c;
}