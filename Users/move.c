#include "move.h"
//uint16_t speed[2][5]={1000}; 数组只初始化了speed[0][0];

#define initial_speed 0
#define speed_length 5

uint8_t light_test[3]={2,2,2};

uint16_t speed[2][speed_length]= {
    {initial_speed, initial_speed, initial_speed, initial_speed, initial_speed},
    {initial_speed, initial_speed, initial_speed, initial_speed, initial_speed}
};
void move_init(void)
{
	HAL_GPIO_WritePin(IN1_GPIO_Port, IN1_Pin,GPIO_PIN_RESET);
	HAL_GPIO_WritePin(IN2_GPIO_Port, IN2_Pin,GPIO_PIN_RESET);
	HAL_GPIO_WritePin(IN3_GPIO_Port, IN3_Pin,GPIO_PIN_RESET);
	HAL_GPIO_WritePin(IN4_GPIO_Port, IN4_Pin,GPIO_PIN_RESET);

	HAL_TIM_PWM_Start_DMA(&htim4,TIM_CHANNEL_1,(uint32_t*)speed[0],speed_length);
	HAL_TIM_PWM_Start_DMA(&htim4,TIM_CHANNEL_2,(uint32_t*)speed[1],speed_length);

}

void wheel_left_stop()
{
	HAL_GPIO_WritePin(IN1_GPIO_Port, IN1_Pin,GPIO_PIN_RESET);
	HAL_GPIO_WritePin(IN2_GPIO_Port, IN2_Pin,GPIO_PIN_RESET);
}

void wheel_right_stop()
{
	HAL_GPIO_WritePin(IN3_GPIO_Port, IN3_Pin,GPIO_PIN_RESET);
	HAL_GPIO_WritePin(IN4_GPIO_Port, IN4_Pin,GPIO_PIN_RESET);
}

void wheel_left_run(int8_t direction)
{
	if(direction==2) //run_back
	{
		HAL_GPIO_WritePin(IN1_GPIO_Port, IN1_Pin,GPIO_PIN_RESET);
		HAL_GPIO_WritePin(IN2_GPIO_Port, IN2_Pin,GPIO_PIN_SET);
	} 
	else if(direction==0) //stop
	{
		wheel_left_stop();
	} 
	else if(direction==1) //run_front
	{
		HAL_GPIO_WritePin(IN1_GPIO_Port, IN1_Pin,GPIO_PIN_SET);
		HAL_GPIO_WritePin(IN2_GPIO_Port, IN2_Pin,GPIO_PIN_RESET);
	} 
}

void wheel_right_run(int8_t direction)
{
	if(direction==2) 
	{
		HAL_GPIO_WritePin(IN3_GPIO_Port, IN3_Pin,GPIO_PIN_RESET);
		HAL_GPIO_WritePin(IN4_GPIO_Port, IN4_Pin,GPIO_PIN_SET);
	} 
	else if(direction==0) 
	{
		wheel_right_stop();
	} 
	else if(direction==1) 
	{
		HAL_GPIO_WritePin(IN3_GPIO_Port, IN3_Pin,GPIO_PIN_SET);
		HAL_GPIO_WritePin(IN4_GPIO_Port, IN4_Pin,GPIO_PIN_RESET);
	} 
}

void move_on(int8_t direction)
{
	wheel_left_run(direction);
	wheel_right_run(direction);
}

void turn_left(int8_t direction)
{
	wheel_left_run(0);
	wheel_right_run(direction);
}

void turn_right(int8_t direction)
{
	wheel_left_run(direction);
	wheel_right_run(0);
}

void turn_left_fast(void)
{
	wheel_left_run(2);
	wheel_right_run(1);
}

void turn_right_fast(void)
{
	wheel_left_run(1);
	wheel_right_run(2);
}

void speedchange(uint16_t value1,uint16_t value2,uint8_t sign)
{
	uint8_t i=0;
	if(sign)
	{
		for(i=0;i<speed_length;i++)
		{
			speed[0][i]+=value1;
			if (speed[0][i]>1000) speed[0][i]=1000;
			speed[1][i]+=value2;
			if (speed[1][i]>1000) speed[1][i]=1000;
		}
	}
	else
	{
		for(i=0;i<speed_length;i++)
		{
			speed[0][i]-=value1;
			if (speed[0][i]<100) speed[0][i]=100;
			speed[1][i]-=value2;
			if (speed[1][i]<100) speed[1][i]=100;
		}
	}
}

void speedset(uint16_t value1,uint16_t value2)
{
	for(uint8_t i=0;i<speed_length;i++)
	{
		speed[0][i]=value1;
		speed[1][i]=value2;
	}
}




