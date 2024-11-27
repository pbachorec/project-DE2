#ifndef ADC_H
#define ADC_H

#include <avr/io.h>

// Inicializace ADC
void adc_init(void);

// Čtení hodnoty z ADC kanálu
uint16_t adc_read(uint8_t channel);

#endif // ADC_H
