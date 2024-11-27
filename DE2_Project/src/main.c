#include "adc.h"
#include "servo.h"
#include "acs712.h"
#include "uart.h"

#include <stdio.h>

#define ACS712_SENSITIVITY 185 // Citlivost senzoru (185 mV/A pro 5A verzi)
#define JOYSTICK_CHANNEL 0       // ADC kanál pro joystick (osa X)
#define ACS712_CHANNEL 1         // ADC kanál pro senzor ACS712
#define NUM_SAMPLES 100           // Počet vzorků pro průměrování

int main(void) {
    uint8_t current_angle = 90; // Servo začne uprostřed
    adc_init();                // Inicializace ADC
    servo_init();              // Inicializace serva
    acs712_init();
    uart_init(9600); // Inicializace UART s rychlostí 9600 baudů

    servo_set_angle(current_angle); // Nastavení serva na počáteční úhel (90°)

    printf("System initialized!\n");

    while (1) {

        // **Ovládání serva pomocí joysticku**
        servo_control_from_joystick(&current_angle, JOYSTICK_CHANNEL);

        // **Měření proudu pomocí ACS712**
        float average_current = acs712_read_current(ACS712_CHANNEL, ACS712_SENSITIVITY);
        int current_mA = (int)(average_current); // Převod na int
        printf("Proud: %d mA\n", current_mA); // Výpis proudu v mA
        _delay_ms(500);
    }
}