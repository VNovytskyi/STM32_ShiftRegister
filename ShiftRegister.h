#ifndef ShiftRegister
#define ShiftRegister

#define cs_strob() cs_reset(); cs_set()

void SR_Set(void);
void SR_Reset(void);

void SR_SetValue(uint16_t value);

void SR_SetPin(uint16_t pin);
void SR_ResetPin(uint16_t pin);

#include "ShiftRegister.c"
#endif
