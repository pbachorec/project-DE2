#ifndef ADC_H
#define ADC_H

#include <avr/io.h>

// Inicializace ADC (nastavení prescaleru a referenčního napětí)
void adc_init(void);

// Čtení hodnoty z daného ADC kanálu (0–7)
uint16_t adc_read(uint8_t channel);

#endif // ADC_H
