#pragma once
#include <array.h>
#include "sys_const.h"

unsigned int const N_size_bits = 8;
unsigned int const N_size = 1<<N_size_bits;
unsigned int const audio_buffer_size = N_size*2;
unsigned int const order = 2;
unsigned int const sample_freq = 48000*8;
unsigned int const max_vol = SYS_CLOCK_MHZ*1e6/sample_freq;

// Per original code, may be within [14,20]
unsigned int const time_bit_scale_factor = 18;
unsigned int const time_scale_factor = 1<<time_bit_scale_factor;

unsigned int const bit_shift_scale_factor = 12;
unsigned int const shift_scale_factor = 1<<bit_shift_scale_factor;

unsigned int const vol_bits = 6;
unsigned int const vol_scale = 1<<vol_bits;

class AudioSystem {
public:
    AudioSystem();

private:
    unsigned int volume;

    array<uint16_t,audio_buffer_size> sampleBuffer;
    uint16_t* samplePtr = (uint16_t*)&sampleBuffer[0];
}