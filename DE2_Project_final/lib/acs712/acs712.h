#ifndef ACS712_H
#define ACS712_H

#include <stdint.h>

// Initialize the ACS712 sensor
void acs712_init(uint8_t channel, float sensitivity, float offset, float ref_voltage);

// Measure current in amperes
float acs712_read_current(void);

#endif // ACS712_H
