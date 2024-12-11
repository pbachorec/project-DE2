#include "measurement.h"
#include "acs712.h"
#include "adc.h"
#include "servo.h"
#include "oled.h"
#include <stdio.h>
#include "timer.h"

// Definition of the voltage divider for measuring 6V with a maximum of 5V on the ADC
//#define R1 10000.0  // Upper resistor of the divider (10 kOhm)
//#define R2 1000.0   // Lower resistor of the divider (2 kOhm)
//#define VOLTAGE_DIVIDER_RATIO ((R1 + R2) / R2) // Divider ratio

// ADC channels
#define JOYSTICK_ADC_CHANNEL 0    // ADC channel for the joystick
#define ACS712_CHANNEL 1          // ADC channel for the ACS712 sensor

// ACS712 sensor settings
#define  ACS712_SENSITIVITY 185  // Sensitivity in V/A
#define ACS712_OFFSET 2500         // Offset in volts
#define ACS712_REF_VOLTAGE 5    // Reference voltage for the ADC in volts

//#define SERVO_PIN PB1             // Pin for the servo

int main(void) {

    // Initialize the ADC
    adc_init();

    // Initialize the ACS712 sensor
    acs712_init(ACS712_CHANNEL,ACS712_SENSITIVITY,ACS712_OFFSET,ACS712_REF_VOLTAGE);

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
        

            oled_gotoxy(0, 0);
            oled_charMode(DOUBLESIZE);
            oled_puts("Project");
            // Current
            oled_gotoxy(0, 4);
            itoa(acs712_read_current,buffer,10);
            oled_puts(buffer);
            oled_puts("mA");

            // Servo angle
            servo_control_from_joystick(&current_angle, JOYSTICK_ADC_CHANNEL);

            oled_gotoxy(0, 6);
            itoa(current_angle,buffer,10);
            oled_puts(buffer);

            oled_display();
        
    }

    return 0;
}
