#include "main.h"
#include "stm32f4xx_hal.h"

void ErrorHandler(void);

int main(void)
{
	RCC_OscInitTypeDef osc_init;
	RCC_ClkInitTypeDef clk_init;
	HAL_Init();
	memset(&osc_init,0,sizeof(osc_init));
	osc_init.OscillatorType = RCC_OSCILLATORTYPE_HSE;
	osc_init.HSEState = RCC_HSE_ON;
	if ( HAL_RCC_OscConfig(&osc_init) != HAL_OK )
	{
		ErrorHandler();
	}

	while (1);

	return 0;
}

void ErrorHandler(void)
{
	while(1);
}
