#include "acs712.h"
#include "adc.h"

#define ADC_REF_VOLTAGE 5000.0 // Referenční napětí v mV

void acs712_init(void) {
    // Není nutné provádět další inicializaci, ADC je již nastaveno
}

float acs712_read_current(uint8_t channel, float sensitivity) {
    if (channel > 7) {
        return 0; // Neplatný kanál
    }
    
    float sum = 0; // Inicializace sumy

    for (uint8_t i = 0; i < 100; i++) {
        uint16_t adc_value = adc_read(channel); // Čtení z ADC
        float voltage = (adc_value / 1023.0) * ADC_REF_VOLTAGE; // Převod na napětí
        float current = (voltage - 2500.0) / sensitivity; // Převod na proud v mA
        sum += current; // Přičtení aktuální hodnoty do sumy
    }

    return sum / 100; // Průměrování a vrácení výsledku
}Takže
