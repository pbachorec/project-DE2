#ifndef MEASUREMENT_H
#define MEASUREMENT_H

#include <stdint.h>

// Initialize the measurement system
void measurement_init(float voltage_divider_ratio, uint8_t voltage_adc_channel);

// Get the measured voltage in volts
float measurement_get_voltage(void);

// Get the measured current in amperes
float measurement_get_current(void);

// Get the measured power in watts
float measurement_get_power(void);

// Get the total consumed energy in watt-hours
float measurement_get_energy(void);

#endif // MEASUREMENT_H