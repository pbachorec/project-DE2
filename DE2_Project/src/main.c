#include "adc.h"
#include "servo.h"

int main(void) {
    uint8_t current_angle = 90; // Servo začne uprostřed
    adc_init();                // Inicializace ADC
    servo_init();              // Inicializace serva

    servo_set_angle(current_angle); // Nastavení serva na počáteční úhel (90°)

    while (1) {
        servo_control_from_joystick(&current_angle, 0); // Ovládání serva joystickem na kanálu 0
    }
}