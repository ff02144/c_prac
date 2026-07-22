#ifndef rom_h
#define rom_h

#include <stdint.h>

int load_rom(const char *filename,uint8_t *memory, uint16_t load_address);

#endif

