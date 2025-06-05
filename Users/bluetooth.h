#ifndef __BLUETOOTH_H__
#define __BLUETOOTH_H__

#include "main.h"
#include "usart.h"
#include "control.h"

#define RXBUFFER_LEN 1
extern uint8_t rxbuff[RXBUFFER_LEN];
extern uint8_t remote_flag;

void bluetooth_start(void);
void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart);

#endif

