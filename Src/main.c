#include "main.h"

#include "usart_ring.h"
#define SIZE_BF 32
UART_HandleTypeDef huart1;

int main(void)
{
  HAL_Init();
  SystemClock_Config();
  MX_GPIO_Init();
  MX_USART1_UART_Init();
  __HAL_UART_ENABLE_IT(&MYUART, UART_IT_RXNE); // включить прерывания usart'a

  while (1)
  {
    if (uart_available()) // есть ли что-то в приёмном буфере, тогда читаем
    {
      char str[SIZE_BF] = {0,};
      uint8_t i = 0;

      while (uart_available())
      {
        str[i++] = uart_read(); // читаем байт
        if (i == SIZE_BF - 1)
        {
          str[i] = '\0';
          break;
        }
        // HAL_Delay(1);
      }
      str[i] = '\0';
      HAL_UART_Transmit(&MYUART, (uint8_t *)str, strlen(str), 100); // эхо
    }
  }
}