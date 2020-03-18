extern SPI_HandleTypeDef hspi2;

void SR_Set(void)
{
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_12, GPIO_PIN_RESET)
}

void SR_Reset(void)
{
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_12, GPIO_PIN_SET);
}

void SR_SetValue(uint16_t value)
{
	 HAL_Delay(1000);
	 txBuff[0] = 0xff;
	 txBuff[1] = 0xff;
	 HAL_SPI_Transmit(&hspi2, txBuff, 2, 5000);
	 cs_strob();
}
