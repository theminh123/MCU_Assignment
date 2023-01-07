#include "timer.h"

//INIT TIMERS
int timer1_flag = 0;
int timer1_counter = 0;

int timer2_flag = 0;
int timer2_counter = 0;

int timer3_flag = 0;
int timer3_counter = 0;

//SET TIMERS
void setTimer1(int duration){
	timer1_counter = duration/TIMER_CYCLE;
	timer1_flag = 0;
}

void setTimer2(int duration){
	timer2_counter = duration/TIMER_CYCLE;
	timer2_flag = 0;
}

void setTimer3(int duration){
	timer3_counter = duration/TIMER_CYCLE;
	timer3_flag = 0;
}

//TIMER DRIVERS
void timer_run(){
	if(timer1_counter > 0){
		timer1_counter--;
		if(timer1_counter == 0) timer1_flag = 1;
	}
	if(timer2_counter > 0){
		timer2_counter--;
		if(timer2_counter == 0) timer2_flag = 1;
	}
	if(timer3_counter > 0){
		timer3_counter--;
		if(timer3_counter == 0) timer3_flag = 1;
	}
}

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim){
	timer_run();
	button_processing();
}
