#include "hc-sr04.h"
uint8_t IS_FIRST_CAPTURE[3]={0};
uint32_t IC_Valbegin[3]={0};
uint32_t IC_Valend[3]={0};
uint32_t difference[3]={0};
float distancebuff[3]={0};
float distance[3]={0};

void dis_measure_init(void)
{
	HAL_TIM_Base_Start(&htim2);
	HAL_TIM_IC_Start_IT(&htim2,TIM_CHANNEL_1);
	HAL_TIM_IC_Start_IT(&htim2,TIM_CHANNEL_2);
	HAL_TIM_IC_Start_IT(&htim2,TIM_CHANNEL_3);
}

void delay_us(uint16_t time)
{
	__HAL_TIM_SET_COUNTER(&htim2,0);
	while(__HAL_TIM_GetCounter(&htim2)<time);
}

void hcsr04_read_left(void)
{
	HAL_GPIO_WritePin(TRIGL_GPIO_Port,TRIGL_Pin,GPIO_PIN_RESET);
	delay_us(2);
	HAL_GPIO_WritePin(TRIGL_GPIO_Port,TRIGL_Pin,GPIO_PIN_SET);
	delay_us(12);
	HAL_GPIO_WritePin(TRIGL_GPIO_Port,TRIGL_Pin,GPIO_PIN_RESET);
	
	__HAL_TIM_ENABLE_IT(&htim2,TIM_IT_CC1);
//	__HAL_TIM_ENABLE_IT(&htim2,TIM_IT_CC2);
//	__HAL_TIM_ENABLE_IT(&htim2,TIM_IT_CC3);
	HAL_Delay(100);
	distance[0]=distancebuff[0];

}

void hcsr04_read_forward(void)
{
	HAL_GPIO_WritePin(TRIGF_GPIO_Port,TRIGF_Pin,GPIO_PIN_RESET);
	delay_us(2);
	HAL_GPIO_WritePin(TRIGF_GPIO_Port,TRIGF_Pin,GPIO_PIN_SET);
	delay_us(12);
	HAL_GPIO_WritePin(TRIGF_GPIO_Port,TRIGF_Pin,GPIO_PIN_RESET);
	
	__HAL_TIM_ENABLE_IT(&htim2,TIM_IT_CC2);
	HAL_Delay(100);
	distance[1]=distancebuff[1];

}

void hcsr04_read_right(void)
{
	HAL_GPIO_WritePin(TRIGR_GPIO_Port,TRIGR_Pin,GPIO_PIN_RESET);
	delay_us(2);
	HAL_GPIO_WritePin(TRIGR_GPIO_Port,TRIGR_Pin,GPIO_PIN_SET);
	delay_us(12);
	HAL_GPIO_WritePin(TRIGR_GPIO_Port,TRIGR_Pin,GPIO_PIN_RESET);
	
	__HAL_TIM_ENABLE_IT(&htim2,TIM_IT_CC3);

	HAL_Delay(100);
	distance[2]=distancebuff[2];

}

void HAL_TIM_IC_CaptureCallback(TIM_HandleTypeDef *htim)
{
	if(htim->Channel== HAL_TIM_ACTIVE_CHANNEL_1)
	{
		if(IS_FIRST_CAPTURE[0] == 0)
		{
			IS_FIRST_CAPTURE[0]=1;
			IC_Valbegin[0] = HAL_TIM_ReadCapturedValue(htim,TIM_CHANNEL_1);
			__HAL_TIM_SET_CAPTUREPOLARITY(htim,TIM_CHANNEL_1,TIM_INPUTCHANNELPOLARITY_FALLING);
		}
		else if(IS_FIRST_CAPTURE[0] == 1)
		{
			IS_FIRST_CAPTURE[0]=0;
			IC_Valend[0] = HAL_TIM_ReadCapturedValue(htim,TIM_CHANNEL_1);
//			__HAL_TIM_SET_COUNTER(htim,0);
			
			if(IC_Valend[0] > IC_Valbegin[0])
			{
				difference[0]= IC_Valend[0]-IC_Valbegin[0];
			}
			else if(IC_Valend[0] < IC_Valbegin[0])
			{
				difference[0]= 0xffff - IC_Valbegin[0] + IC_Valend[0];
			}
			distancebuff[0]=difference[0] * 0.017; //cm
			if(distancebuff[0]>560) distancebuff[0]=560;
			
			__HAL_TIM_SET_CAPTUREPOLARITY(htim,TIM_CHANNEL_1,TIM_INPUTCHANNELPOLARITY_RISING);
			__HAL_TIM_DISABLE_IT(&htim2,TIM_IT_CC1);
		}
	}
	
  else if(htim->Channel== HAL_TIM_ACTIVE_CHANNEL_2)
	{
		if(IS_FIRST_CAPTURE[1] == 0)
		{
			IS_FIRST_CAPTURE[1]=1;
			IC_Valbegin[1] = HAL_TIM_ReadCapturedValue(htim,TIM_CHANNEL_2);
			__HAL_TIM_SET_CAPTUREPOLARITY(htim,TIM_CHANNEL_2,TIM_INPUTCHANNELPOLARITY_FALLING);
		}
		else if(IS_FIRST_CAPTURE[1] == 1)
		{
			IS_FIRST_CAPTURE[1]=0;
			IC_Valend[1] = HAL_TIM_ReadCapturedValue(htim,TIM_CHANNEL_2);
//			__HAL_TIM_SET_COUNTER(htim,0);
			
			if(IC_Valend[1] > IC_Valbegin[1])
			{
				difference[1]= IC_Valend[1]-IC_Valbegin[1];
			}
			else if(IC_Valend[1] < IC_Valbegin[1])
			{
				difference[1]= 0xffff - IC_Valbegin[1] + IC_Valend[1];
			}
			distancebuff[1]=difference[1] * 0.017; //cm
			if(distancebuff[1]>560) distancebuff[1]=560;
			
			__HAL_TIM_SET_CAPTUREPOLARITY(htim,TIM_CHANNEL_2,TIM_INPUTCHANNELPOLARITY_RISING);
			__HAL_TIM_DISABLE_IT(&htim2,TIM_IT_CC2);
		 }
	 }
	
  else if(htim->Channel== HAL_TIM_ACTIVE_CHANNEL_3)
	{
		if(IS_FIRST_CAPTURE[2] == 0)
		{
			IS_FIRST_CAPTURE[2]=1;
			IC_Valbegin[2] = HAL_TIM_ReadCapturedValue(htim,TIM_CHANNEL_3);
			__HAL_TIM_SET_CAPTUREPOLARITY(htim,TIM_CHANNEL_3,TIM_INPUTCHANNELPOLARITY_FALLING);
		}
		else if(IS_FIRST_CAPTURE[2] == 1)
		{
			IS_FIRST_CAPTURE[2]=0;
			IC_Valend[2] = HAL_TIM_ReadCapturedValue(htim,TIM_CHANNEL_3);
//			__HAL_TIM_SET_COUNTER(htim,0);
			
			if(IC_Valend[2] > IC_Valbegin[2])
			{
				difference[2]= IC_Valend[2]-IC_Valbegin[2];
			}
			else if(IC_Valend[2] < IC_Valbegin[2])
			{
				difference[2]= 0xffff - IC_Valbegin[2] + IC_Valend[2];
			}
			distancebuff[2]=difference[2] * 0.017; //cm
			if(distancebuff[2]>560) distancebuff[2]=560;
			
			__HAL_TIM_SET_CAPTUREPOLARITY(htim,TIM_CHANNEL_3,TIM_INPUTCHANNELPOLARITY_RISING);
			__HAL_TIM_DISABLE_IT(&htim2,TIM_IT_CC3);
		 }
	 }
}

void get_distance(void)
{
		hcsr04_read_left();
		HAL_Delay(100);
		hcsr04_read_forward();
		HAL_Delay(100);
		hcsr04_read_right();
		HAL_Delay(100);
		HAL_GPIO_TogglePin(LED_GPIO_Port,LED_Pin);
}
	

