#ifndef NRF_ShiftRegister
#define NRF_ShiftRegister

#define cs_strob() cs_reset(); cs_set()

void SR_Set(void);
void SR_Reset(void);

void SR_SetValue(uint16_t value);

#include "NRF_ShiftRegister.c"
#endif
