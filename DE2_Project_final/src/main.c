#include "measurement.h"
#include "acs712.h"
#include "adc.h"
#include "servo.h"
#include "oled.h"
#include <stdio.h>
#include "timer.h"

// Definition of the voltage divider for measuring 6V with a maximum of 5V on the ADC
#define R1 10000.0  // Upper resistor of the divider (10 kOhm)
#define R2 2000.0   // Lower resistor of the divider (2 kOhm)
#define VOLTAGE_DIVIDER_RATIO ((R1 + R2) / R2) // Divider ratio

// ADC channels
#define JOYSTICK_ADC_CHANNEL 0    // ADC channel for the joystick
#define ACS712_CHANNEL 1          // ADC channel for the ACS712 sensor
#define VOLTAGE_ADC_CHANNEL 2     // ADC channel for voltage measurement

// ACS712 sensor settings
#define ACS712_OFFSET 2.5         // Offset in volts
#define ACS712_REF_VOLTAGE 5.0    // Reference voltage for the ADC in volts
#define ACS712_SENSITIVITY 0.185  // Sensitivity in V/A

#define SERVO_PIN PB1             // Pin for the servo

int main(void) {
    timer0_init(); // Initialize the timer for millis()

    // Initialize the ADC
    adc_init();

    // Initialize the ACS712 sensor
    acs712_init(ACS712_CHANNEL, ACS712_SENSITIVITY, ACS712_OFFSET, ACS712_REF_VOLTAGE);

    // Initialize voltage and power measurement
    measurement_init(VOLTAGE_DIVIDER_RATIO, VOLTAGE_ADC_CHANNEL);

    // Initialize the OLED display
    oled_init(OLED_DISP_ON);
    oled_clrscr();

    // Initialize the servo
    servo_init();

    uint8_t current_angle = 90; // Default servo angle
    servo_set_angle(current_angle);

    char buffer[16]; // For storing text to display

    // Main loop
    while (1) {
        // Control the servo using the joystick
        servo_control_from_joystick(&current_angle, JOYSTICK_ADC_CHANNEL);

        // Retrieve measured values
        float voltage = measurement_get_voltage();
        float current = measurement_get_current();
        float power = measurement_get_power();
        float energy = measurement_get_energy();

        // Display measured values on the OLED display
        oled_clrscr();

        // Voltage
        oled_gotoxy(0, 0);
        snprintf(buffer, sizeof(buffer), "Voltage: %.2f V", voltage);
        oled_puts(buffer);

        // Current
        oled_gotoxy(0, 1);
        snprintf(buffer, sizeof(buffer), "Current: %.2f A", current);
        oled_puts(buffer);

        // Power
        oled_gotoxy(0, 2);
        snprintf(buffer, sizeof(buffer), "Power: %.2f W", power);
        oled_puts(buffer);

        // Energy
        oled_gotoxy(0, 3);
        snprintf(buffer, sizeof(buffer), "Energy: %.2f Wh", energy);
        oled_puts(buffer);

        // Servo angle
        oled_gotoxy(0, 4);
        snprintf(buffer, sizeof(buffer), "Servo: %d°", current_angle);
        oled_puts(buffer);

        oled_display();
/*
        // Print to console
        printf("Voltage: %.2f V\n", voltage);
        printf("Current: %.2f A\n", current);
        printf("Power: %.2f W\n", power);
        printf("Energy: %.2f Wh\n", energy);
        printf("Servo: %d°\n", current_angle);
*/
        // Replace delay with time-based updates
        static uint32_t last_update_time = 0;
        uint32_t current_time = millis();
        if (current_time - last_update_time < 500) {
            continue;
        }
        last_update_time = current_time;
    }

    return 0;
}
