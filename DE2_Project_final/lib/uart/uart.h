#ifndef UART_H
#define UART_H

#include <stdio.h>
#include <stdint.h>

// Initialize UART
void uart_init(uint32_t baudrate);

// Send a single character via UART
int uart_putchar(char c, FILE *stream);

#endif // UART_H