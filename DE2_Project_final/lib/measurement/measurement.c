#include "measurement.h"
#include "timer.h"
#include "acs712.h"
#include "adc.h"

// Static variables to hold configuration and measurements
static float voltage_divider_ratio; // Ratio of the voltage divider
static uint8_t voltage_adc_channel; // ADC channel used for voltage measurement
static float total_energy = 0.0;    // Total consumed energy in watt-hours
static uint32_t last_update_time = 0; // Last update time in milliseconds

// Initialize the measurement system with the voltage divider ratio and ADC channel
void measurement_init(float divider_ratio, uint8_t adc_channel) {
    voltage_divider_ratio = divider_ratio; // Store the voltage divider ratio
    voltage_adc_channel = adc_channel;    // Store the ADC channel for voltage
    total_energy = 0.0;                   // Reset total energy to zero
    last_update_time = millis();          // Initialize the last update time
}

// Get the measured voltage in volts
float measurement_get_voltage(void) {
    uint16_t adc_value = adc_read(voltage_adc_channel); // Read ADC value
    return (adc_value / 1023.0) * 5.0 * voltage_divider_ratio; // Convert to voltage
}

// Get the measured current in amperes
float measurement_get_current(void) {
    return acs712_read_current(); // Use the ACS712 library to read the current
}

// Calculate and return the measured power in watts
float measurement_get_power(void) {
    return measurement_get_voltage() * measurement_get_current(); // Power = Voltage * Current
}

// Calculate and return the total consumed energy in watt-hours
float measurement_get_energy(void) {
    uint32_t current_time = millis(); // Get the current time in milliseconds
    if (last_update_time > 0) {
        float power = measurement_get_power(); // Calculate the current power
        // Calculate elapsed time in hours
        float elapsed_time_hours = (current_time - last_update_time) / 3600000.0;
        // Increment total energy by the power multiplied by elapsed time
        total_energy += power * elapsed_time_hours;
    }
    last_update_time = current_time; // Update the last update time
    return total_energy;             // Return the total energy
}
