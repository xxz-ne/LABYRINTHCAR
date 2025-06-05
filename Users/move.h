#ifndef __MOVE_H__
#define __MOVE_H__

#include "main.h"
#include "tim.h"

extern uint16_t speed[2][5];

extern uint8_t light_test[3];

void move_init(void);
void move_on(int8_t direction); // direction=+-1;
void turn_left(int8_t direction);
void turn_right(int8_t direction);
void turn_left_fast(void);
void turn_right_fast(void);
void speedchange(uint16_t value1,uint16_t value2,uint8_t sign);
void speedset(uint16_t value1,uint16_t value2);

#endif

