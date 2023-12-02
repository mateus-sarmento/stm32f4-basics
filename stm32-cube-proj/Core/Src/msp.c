#include "main.h"

void HAL_MspInit(void)
{
	// Set up the priority grouping of the arm cortex
	HAL_NVIC_SetPriorityGrouping(NVIC_PRIORITYGROUP_4);

	//Enable required system exceptions of the arm cortex
	SBC->SHCSR |= 0x7<<16; //usage fault, mem fault and bus fault

	//Config the priority for the system exceptions

	HAL_NVIC_SetPriority(MemoryManagement_IRQn,0,0);
	HAL_NVIC_SetPriority(BusFault_IRQn, 0, 0);
	HAL_NVIC_SetPriority(UsageFault_IRQn, 0, 0);

}
