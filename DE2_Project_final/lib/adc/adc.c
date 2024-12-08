#include "adc.h"

void adc_init(void) {
    // Configure ADC: reference voltage AVcc, prescaler 64
    ADMUX = (1 << REFS0); // AVcc as the reference voltage
    ADCSRA |= (1 << ADEN) | (1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0); // Enable ADC and set prescaler to 64
}

uint16_t adc_read(uint8_t channel) {
    // Set the ADC channel (0–7)
    ADMUX = (ADMUX & 0xF8) | (channel & 0x07);

    // Start the conversion
    ADCSRA |= (1 << ADSC);

    // Wait until the conversion is complete
    while (ADCSRA & (1 << ADSC));

    // Read the result
    uint16_t adc_value = ADCL;
    adc_value |= (ADCH << 8);

    return adc_value;
}