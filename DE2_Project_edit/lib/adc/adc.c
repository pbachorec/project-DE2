#include "adc.h"

void adc_init(void) {
    // Nastavení ADC: referenční napětí AVcc, prescaler 64
    ADMUX = (1 << REFS0); // AVcc jako referenční napětí
    ADCSRA = (1 << ADEN) | (1 << ADPS2) | (1 << ADPS1); // Zapnutí ADC, prescaler 64
}

uint16_t adc_read(uint8_t channel) {
    // Vybereme kanál (0–7)
    ADMUX = (ADMUX & 0xF8) | (channel & 0x07);

    // Zahájíme konverzi
    ADCSRA |= (1 << ADSC);

    // Počkáme, dokud konverze neskončí
    while (ADCSRA & (1 << ADSC));

    // Vrátíme výsledek
    return ADC;
}
