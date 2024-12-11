#include "servo.h"
#include "adc.h"

void servo_init(void) {
    TCCR1A |= (1 << WGM11) | (1 << COM1A1); // Fast PWM, non-inverting
    TCCR1B |= (1 << WGM13) | (1 << WGM12) | (1 << CS11); // Prescaler 8
    ICR1 = 40000; // Set PWM period (20 ms for 50 Hz)
    DDRB |= (1 << PB1); // Pin 9 (OC1A) output
}

void servo_set_angle(uint8_t angle) {
    uint16_t pulse_width = 1100 + (angle * (2900 - 1100)) / 90; // Calculate pulse width based on angle
    OCR1A = pulse_width; // Set pulse width
}

void servo_control_from_joystick(uint8_t *current_angle, uint8_t adc_channel) {
    uint16_t adc_value = adc_read(adc_channel); // Read value from ADC channel

    if (adc_value < 100) { // Joystick in the far-left position
        if (*current_angle > 0) {
            (*current_angle)--; // Move the servo left
            servo_set_angle(*current_angle);
        }
    } else if (adc_value > 900) { // Joystick in the far-right position
        if (*current_angle < 180) {
            (*current_angle)++; // Move the servo right
            servo_set_angle(*current_angle);
        }
    }
}
