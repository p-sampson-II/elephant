AudioSystem::AudioSystem(I2C_HandleTypeDef& hi2c, DMA_HandleTypeDef& hdma_spi_tx, I2S_HandleTypeDef& hi2s,
                            array<uint16_t,audio_buffer_size>& sampleBuffer) :
                        hi2c(&hi2c), hdma_spi_tx(&hdma_spi_tx), hi2s(&hi2s), sampleBuffer(&sampleBuffer)
            {}

AudioSystem::AudioSystem(I2C_HandleTypeDef& hi2c, DMA_HandleTypeDef& hdma_spi_tx, I2S_HandleTypeDef& hi2s) :
                        hi2c(&hi2c), hdma_spi_tx(&hdma_spi_tx), hi2s(&hi2s), sampleBuffer(nullptr)
            {}

AudioSystem::AudioSystem() : hi2c(nullptr), hdma_spi_tx(nullptr), hi2s(nullptr), sampleBuffer(nullptr)
            {}

void AudioSystem::play() {
    if(!isBufferSet) { return; }

    while (hi2s->State != HAL_I2S_STATE_READY) {}
	if (HAL_I2S_Transmit_DMA(*hi2s, (uint16_t*) sampleBuffer.data(),
        (uint16_t) sampleBuffer.size()) != HAL_OK) {
		Error_Handler();
	}
}

void AudioSystem::setBuffer(array<uint16_t,audio_buffer_size>& sampleBuffer) {
    this->sampleBuffer = &sampleBuffer;
}

inline bool AudioSystem::isBufferSet() {
    return (this->sampleBuffer != nullptr);
}
