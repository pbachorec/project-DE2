#include "acs712.h"
#include "adc.h"
#include <util/delay.h> // Pro _delay_ms

void acs712_init(void) {
    // Není nutné provádět další inicializaci, ADC je již nastaveno
}

float acs712_read_current(uint8_t channel, float sensitivity) {
    float sum = 0; // Inicializace sumy

    for (uint8_t i = 0; i < 100; i++) {
        uint16_t adc_value = adc_read(channel); // Čtení z ADC
        float voltage = (adc_value / 1023.0) * 5000.0; // Převod na napětí v mV
        float current = (voltage - 2500.0) / sensitivity; // Převod na proud v mA
        sum += current; // Přičtení aktuální hodnoty do sumy
        _delay_ms(10); // Krátká prodleva
    }

    return sum / 100; // Průměrování a vrácení výsledku
}


