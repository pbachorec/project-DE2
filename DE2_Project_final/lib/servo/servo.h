#ifndef SERVO_H
#define SERVO_H

#include <avr/io.h>
#include "adc.h"

// Initialize the servo (PWM)
void servo_init(void);

// Set the servo angle (0–180°)
void servo_set_angle(uint8_t angle);

// Control the servo using a joystick (single axis)
void servo_control_from_joystick(uint8_t *current_angle, uint8_t adc_channel);

#endif // SERVO_H