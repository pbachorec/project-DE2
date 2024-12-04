#include "servo.h"
#include "adc.h" // Přidání hlavičkového souboru pro funkce ADC

void servo_init(void) {
    TCCR1A |= (1 << WGM11) | (1 << COM1A1); // Fast PWM, non-inverting
    TCCR1B |= (1 << WGM13) | (1 << WGM12) | (1 << CS11); // Prescaler 8
    ICR1 = 40000; // Nastavení periody PWM (20 ms pro 50 Hz)
    DDRB |= (1 << PB1); // Pin 9 (OC1A) jako výstup
}

void servo_set_angle(uint8_t angle) {
    uint16_t pulse_width = 1100 + (angle * (2900 - 1100)) / 90;
    OCR1A = pulse_width;
}

void servo_control_from_joystick(uint8_t *current_angle, uint8_t adc_channel) {
    uint16_t adc_value = adc_read(adc_channel); // Čtení hodnoty z ADC kanálu

    if (adc_value < 100) { // Joystick v levé krajní poloze
        if (*current_angle > 0) {
            (*current_angle)--; // Posuneme servo doleva
            servo_set_angle(*current_angle);
            //_delay_ms(50); // Krátká prodleva
        }
    } else if (adc_value > 900) { // Joystick v pravé krajní poloze
        if (*current_angle < 180) {
            (*current_angle)++; // Posuneme servo doprava
            servo_set_angle(*current_angle);
            //_delay_ms(50); // Krátká prodleva
        }
    }
}
