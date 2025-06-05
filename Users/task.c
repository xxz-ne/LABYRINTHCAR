#include "task.h"
uint8_t GLOBAL_INIT_FLAG = 0;

void Init_Task(void const * argument)
{
	dis_measure_init();
	move_init();
	move_on(1);
	ssd1306_Init();
	bluetooth_start();
	GLOBAL_INIT_FLAG = 1;
	vTaskSuspend(NULL);	
	
  for(;;)
  {
    osDelay(1);
  }
	
}

void Measuredist_Task(void const * argument)
{
  for(;;)
  {
	if(GLOBAL_INIT_FLAG) get_distance();
    osDelay(1);
  }
}

void OLED_Task(void const * argument)
{
	ssd1306_TestAll();
  for(;;)
  {
    osDelay(1);
  }

}

void Movecontrol_Task(void const * argument)
{

  for(;;)
  {
	mode_judge();
	move_control(move_mode);
    osDelay(1);
  }
}

void LIGHT_TEST_TASK(void const * argument)
{
  for(;;)
  {
	light_test[0]=HAL_GPIO_ReadPin(LIGHT_LEFT_GPIO_Port,LIGHT_LEFT_Pin);
	light_test[1]=HAL_GPIO_ReadPin(LIGHT_FRONT_GPIO_Port,LIGHT_FRONT_Pin);
	light_test[2]=HAL_GPIO_ReadPin(LIGHT_RIGHT_GPIO_Port,LIGHT_RIGHT_Pin);
    osDelay(1);
  }
  
}

