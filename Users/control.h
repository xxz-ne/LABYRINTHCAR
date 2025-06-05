#ifndef __CONTROL_H__
#define __CONTROL_H__

#define road_width 50
#define set_width 20
#include "hc-sr04.h"
#include "move.h"
#include "bluetooth.h"

extern uint8_t move_mode;

void mode_judge(void);
void move_control(uint8_t mode);



#endif

