#include "uart.h"
#include <avr/io.h>

#define F_CPU 16000000UL // Frekvence procesoru (nastavte podle svého mikrokontroléru)

static FILE uart_stdout = FDEV_SETUP_STREAM(uart_putchar, NULL, _FDEV_SETUP_WRITE);

void uart_init(uint32_t baudrate) {
    uint16_t ubrr_value = (F_CPU / (16UL * baudrate)) - 1; // Výpočet UBRR hodnoty

    // Nastavení rychlosti
    UBRR0H = (uint8_t)(ubrr_value >> 8);
    UBRR0L = (uint8_t)ubrr_value;

    // Povolení vysílače
    UCSR0B = (1 << TXEN0);

    // Nastavení formátu: 8 datových bitů, 1 stop bit, bez parity
    UCSR0C = (1 << UCSZ01) | (1 << UCSZ00);

    // Nastavení standardního výstupu na UART
    stdout = &uart_stdout;
}

int uart_putchar(char c, FILE *stream) {
    if (c == '\n') uart_putchar('\r', stream); // Přidání návratu na začátek řádku
    while (!(UCSR0A & (1 << UDRE0)));         // Čekání, než se uvolní buffer
    UDR0 = c;                                 // Odeslání znaku
    return 0;
}
