#include "fsm_auto.h"

//FSM = 4 STATES = R-G -> R-Y -> G-R -> Y-R
void fsm_automatic() {
	switch(status) {
		case INIT: //FIRST a.k.a INIT case R-G, to setup
			status=AUTO_RED_GREEN;
			setTimer1(1000);
			counter = timer_red1;

			HAL_GPIO_WritePin(TrafficLight1_0_GPIO_Port, TrafficLight1_0_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(TrafficLight1_1_GPIO_Port, TrafficLight1_1_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(TrafficLight2_0_GPIO_Port, TrafficLight2_0_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(TrafficLight2_1_GPIO_Port, TrafficLight2_1_Pin, GPIO_PIN_SET);

			displayCounter();
			break;
		case AUTO_RED_GREEN: //FIRST again R-G
			if(timer1_flag == 1){
				counter--;
				setTimer1(1000);
				if(counter == timer_yellow2){
					HAL_GPIO_WritePin(TrafficLight2_0_GPIO_Port, TrafficLight2_0_Pin, GPIO_PIN_SET);
					HAL_GPIO_WritePin(TrafficLight2_1_GPIO_Port, TrafficLight2_1_Pin, GPIO_PIN_SET);
					status = AUTO_RED_YELLOW;
				}
				displayCounter();
			}
			break;
		case AUTO_RED_YELLOW: //SECOND R-Y
			if(timer1_flag == 1){
				counter--;
				setTimer1(1000);
				if(counter == 0){
					counter = timer_green1;
					HAL_GPIO_WritePin(TrafficLight1_0_GPIO_Port, TrafficLight1_0_Pin, GPIO_PIN_RESET);
					HAL_GPIO_WritePin(TrafficLight1_1_GPIO_Port, TrafficLight1_1_Pin, GPIO_PIN_SET);
					HAL_GPIO_WritePin(TrafficLight2_0_GPIO_Port, TrafficLight2_0_Pin, GPIO_PIN_SET);
					HAL_GPIO_WritePin(TrafficLight2_1_GPIO_Port, TrafficLight2_1_Pin, GPIO_PIN_RESET);
					status = AUTO_GREEN_RED;
				}
				displayCounter();
			}
			break;
		case AUTO_GREEN_RED: //THIRD G-R
			if(timer1_flag == 1){
				counter--;
				setTimer1(1000);
				if(counter == 0){
					counter = timer_yellow1;
					HAL_GPIO_WritePin(TrafficLight1_0_GPIO_Port, TrafficLight1_0_Pin, GPIO_PIN_SET);
					HAL_GPIO_WritePin(TrafficLight1_1_GPIO_Port, TrafficLight1_1_Pin, GPIO_PIN_SET);
					status = AUTO_YELLOW_RED;
				}
				displayCounter();
			}
			break;
		case AUTO_YELLOW_RED: //FOURTH Y-R
			if(timer1_flag == 1){
				counter--;
				setTimer1(1000);
				if(counter == 0){
					counter = timer_red1;
					HAL_GPIO_WritePin(TrafficLight1_0_GPIO_Port, TrafficLight1_0_Pin, GPIO_PIN_SET);
					HAL_GPIO_WritePin(TrafficLight1_1_GPIO_Port, TrafficLight1_1_Pin, GPIO_PIN_RESET);
					HAL_GPIO_WritePin(TrafficLight2_0_GPIO_Port, TrafficLight2_0_Pin, GPIO_PIN_RESET);
					HAL_GPIO_WritePin(TrafficLight2_1_GPIO_Port, TrafficLight2_1_Pin, GPIO_PIN_SET);
					status = AUTO_RED_GREEN;
				}
				displayCounter();
			}
			break;
		//AND RESET TO FIRST
	}
}
