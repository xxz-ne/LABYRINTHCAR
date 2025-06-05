#include "bluetooth.h"
#include "move.h"
uint8_t rxbuff[RXBUFFER_LEN]={0};
uint8_t remote_flag=0;

void bluetooth_start(void)
{
  __HAL_UART_ENABLE_IT(&huart3,UART_IT_IDLE);  
	HAL_UART_Receive_DMA(&huart3,rxbuff,RXBUFFER_LEN); 
}

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
	if(huart==&huart3)
	{
		remote_flag=1;
		switch(rxbuff[0])
		{
            case 0x00:  move_on(0);    break; 
			case 0x01:  move_on(1); speedset(450,450);   break;
			case 0x02:  move_on(2);   break; 
			case 0x03:  turn_left(1);  break;
			case 0x04:  turn_right(1);  break;
			case 0x05:  speedchange(50,50,1); break;
			case 0x09:  speedchange(50,50,0); break;
			case 0x06:  speedset(450,450); break;
			case 0x07: turn_left_fast();  break;
			case 0x08: turn_right_fast();  break;
			default:  speedset(0,0); 
		}
	}
	
}

