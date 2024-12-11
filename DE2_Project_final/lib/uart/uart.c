#include "uart.h"
#include <avr/io.h>

#define F_CPU 16000000UL // Processor frequency (adjust according to your microcontroller)

static FILE uart_stdout = FDEV_SETUP_STREAM(uart_putchar, NULL, _FDEV_SETUP_WRITE);

void uart_init(uint32_t baudrate) {
    uint16_t ubrr_value = (F_CPU / (16UL * baudrate)) - 1; // Calculate UBRR value

    // Set baud rate
    UBRR0H = (uint8_t)(ubrr_value >> 8);
    UBRR0L = (uint8_t)ubrr_value;

    // Enable transmitter
    UCSR0B = (1 << TXEN0);

    // Set format: 8 data bits, 1 stop bit, no parity
    UCSR0C = (1 << UCSZ01) | (1 << UCSZ00);

    // Set standard output to UART
    stdout = &uart_stdout;
}

int uart_putchar(char c, FILE *stream) {
    if (c == '\n') uart_putchar('\r', stream); // Add carriage return for new lines
    while (!(UCSR0A & (1 << UDRE0)));         // Wait until the buffer is free
    UDR0 = c;                                 // Send the character
    return 0;
}