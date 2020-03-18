extern SPI_HandleTypeDef hspi2;

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
	txBuff[0] = 0xff;
	txBuff[1] = 0xff;
	HAL_SPI_Transmit(&hspi2, txBuff, 2, 5000);
	SR_Reset();
	SR_Set();
}
