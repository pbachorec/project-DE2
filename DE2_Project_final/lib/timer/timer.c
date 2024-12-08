#include "timer.h"

volatile uint32_t milliseconds = 0;

ISR(TIMER0_OVF_vect) {
    milliseconds++;
    TCNT0 = 6; // Restart timer for a 1ms interval
}

void timer0_init(void) {
    TCCR0A = 0;                      // Normal mode
    TCCR0B = (1 << CS01) | (1 << CS00); // Prescaler 64
    TIMSK0 = (1 << TOIE0);           // Enable overflow interrupt
    TCNT0 = 6;                       // Initialize timer to a value for 1ms
    sei();                           // Enable global interrupts
}

uint32_t millis(void) {
    uint32_t ms;
    cli();                           // Disable interrupts for consistency
    ms = milliseconds;
    sei();                           // Re-enable interrupts
    return ms;
}