#ifndef ADC_H
#define ADC_H

#include <avr/io.h>

// Initialize ADC (set prescaler and reference voltage)
void adc_init(void);

// Read the value from the specified ADC channel (0–7)
uint16_t adc_read(uint8_t channel);

#endif // ADC_H