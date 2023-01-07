#ifndef INC_TIMER_H_
#define INC_TIMER_H_

#include "main.h"
#include "button.h"

#define TIMER_CYCLE 10

extern int timer1_flag;
extern int timer2_flag;
extern int timer3_flag;

void setTimer1(int);
void setTimer2(int);
void setTimer3(int);
void timer_run(void);

#endif /* INC_TIMER_H_ */
