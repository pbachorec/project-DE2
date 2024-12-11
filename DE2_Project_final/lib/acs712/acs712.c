#include "acs712.h"
#include "adc.h"

// Static variables to store ACS712 configuration
static uint8_t acs712_channel;      // ADC channel for the ACS712 sensor
static uint16_t acs712_sensitivity;   // Sensitivity in V/A
static uint16_t acs712_offset;        // Offset in volts
static uint16_t acs712_ref_voltage;   // Reference voltage of the ADC in volts

// Initialize the ACS712 sensor with configuration parameters
void acs712_init(uint8_t channel, uint16_t sensitivity, uint16_t offset, uint16_t ref_voltage) {
    acs712_channel = channel;          // Store the ADC channel
    acs712_sensitivity = sensitivity;  // Store the sensitivity
    acs712_offset = offset;            // Store the offset
    acs712_ref_voltage = ref_voltage;  // Store the reference voltage
}

// Read and calculate the current measured by the ACS712 sensor
uint16_t acs712_read_current(void) {
    uint16_t sum = 0.0; // Initialize the sum of measurements

    for (uint8_t i = 0; i < 100; i++) {
        uint16_t adc_value = adc_read(acs712_channel); // Read value from ADC
        uint16_t voltage = (adc_value / 1023.0) * acs712_ref_voltage; // Convert to voltage in volts
        uint16_t current = (voltage - acs712_offset) / acs712_sensitivity; // Convert to current in amperes
        sum += current; // Add the current value to the sum
    }

    return sum / 100.0; // Return the averaged result
}