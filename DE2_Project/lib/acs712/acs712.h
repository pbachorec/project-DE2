#ifndef ACS712_H
#define ACS712_H

#include <stdint.h>

// Inicializace ACS712 (volitelné, pokud potřebujete nastavení)
void acs712_init(void);

// Měření proudu v ampérech
float acs712_read_current(uint8_t channel, float sensitivity);

#endif // ACS712_H
