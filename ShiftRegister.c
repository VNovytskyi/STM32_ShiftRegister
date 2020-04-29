extern SPI_HandleTypeDef hspi2;

uint16_t shiftRegisterValue = 0x00;

inline void SR_Set(void)
{
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_12, GPIO_PIN_RESET);
}

inline void SR_Reset(void)
{
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_12, GPIO_PIN_SET);
}

void SR_SetValue(uint16_t value)
{
	uint8_t txBuff[2] = {0};
	txBuff[0] = (uint8_t)(value >> 8);
	txBuff[1] = (uint8_t)value;
	HAL_SPI_Transmit(&hspi2, txBuff, 2, 5000);
	SR_Reset();
	SR_Set();
}

void SR_SetPin(uint16_t pin)
{
	shiftRegisterValue |= 1 << pin;
	SR_SetValue(shiftRegisterValue);
}

void SR_ResetPin(uint16_t pin)
{
	shiftRegisterValue &= ~(1 << pin);
	SR_SetValue(shiftRegisterValue);
}
