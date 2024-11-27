#ifndef SERVO_H
#define SERVO_H

#include <avr/io.h>
#include <util/delay.h>
#include "adc.h"

// Inicializace serva (PWM)
void servo_init(void);

// Nastavení úhlu serva (0–180°)
void servo_set_angle(uint8_t angle);

// Ovládání serva joystickem (pouze jedna osa)
void servo_control_from_joystick(uint8_t *current_angle, uint8_t adc_channel);

#endif // SERVO_H
