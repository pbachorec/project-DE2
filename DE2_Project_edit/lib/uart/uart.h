#ifndef UART_H
#define UART_H

#include <stdio.h>
#include <stdint.h>

// Inicializace UART
void uart_init(uint32_t baudrate);

// Odeslání jednoho znaku přes UART
int uart_putchar(char c, FILE *stream);

#endif // UART_H
