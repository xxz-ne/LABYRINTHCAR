#ifndef __HC_SR04_H__
#define __HC_SR04_H__

#include "main.h"
#include "tim.h"

extern float distance[3];
extern float distancebuff[3];
extern	uint8_t IS_FIRST_CAPTURE[3];
extern	uint32_t IC_Valbegin[3];
extern	uint32_t IC_Valend[3];
extern	uint32_t difference[3];

void dis_measure_init(void);
void delay_us(uint16_t time);
void hcsr04_read_left(void);
void hcsr04_read_right(void);
void hcsr04_read_forward(void);
void get_distance(void);

void HAL_TIM_IC_CaptureCallback(TIM_HandleTypeDef *htim);

#endif

