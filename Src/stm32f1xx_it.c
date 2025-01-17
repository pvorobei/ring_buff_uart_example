#include "main.h"
#include "stm32f1xx_it.h"

#include "usart_ring.h"

extern volatile uint16_t rx_buffer_head;
extern volatile uint16_t rx_buffer_tail;
extern unsigned char rx_buffer[UART_RX_BUFFER_SIZE];

extern UART_HandleTypeDef huart1;

void NMI_Handler(void)
{}

void HardFault_Handler(void)
{
  while (1){}
}

void MemManage_Handler(void)
{
  while (1) {}
}

void BusFault_Handler(void)
{
  while (1){}
}

void UsageFault_Handler(void)
{
  while (1){}
}
void SVC_Handler(void){}

void DebugMon_Handler(void)
{}

void PendSV_Handler(void)
{}

void SysTick_Handler(void)
{
  HAL_IncTick();
}

void USART1_IRQHandler(void)
{
  /* USER CODE BEGIN USART1_IRQn 0 */
	if((MYUART.Instance->SR & USART_SR_RXNE) != RESET)
	{
		uint8_t rbyte = (uint8_t)(MYUART.Instance->DR & (uint8_t)0x00FF); // читает байт из регистра
		uint16_t i = (uint16_t)(rx_buffer_head + 1) % UART_RX_BUFFER_SIZE;

		if(i != rx_buffer_tail)
		{
			rx_buffer[rx_buffer_head] = rbyte;
			rx_buffer_head = i;
		}
	}
	return;
  HAL_UART_IRQHandler(&huart1);
}

