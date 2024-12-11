#ifndef ACS712_H
#define ACS712_H

#include <stdint.h>

// Initialize the ACS712 sensor
void acs712_init(uint8_t channel, uint16_t sensitivity, uint16_t offset, uint16_t ref_voltage);

// Measure current in amperes
uint16_t acs712_read_current(void);

#endif // ACS712_H