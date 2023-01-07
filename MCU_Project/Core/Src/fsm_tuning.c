#include "fsm_tuning.h"

void fsm_tuning() {
	switch(status) {
	case TUNING_RED1:
		if(timer1_flag==1){
			timer1_flag = 0;
			setTimer1(1000);
			HAL_GPIO_TogglePin(TrafficLight1_0_GPIO_Port, TrafficLight1_0_Pin);
		}
		if(isButtonPressed(1)) {
			status = AUTO_RED_GREEN;
			timer_red1 = counter;
			if(timer_red1 <= timer_yellow2) timer_yellow2 = 1;
			timer_green2 = timer_red1 - timer_yellow2;
			setTimer1(1000);
			counter = timer_red1;

			HAL_GPIO_WritePin(TrafficLight1_0_GPIO_Port, TrafficLight1_0_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(TrafficLight1_1_GPIO_Port, TrafficLight1_1_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(TrafficLight2_0_GPIO_Port, TrafficLight2_0_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(TrafficLight2_1_GPIO_Port, TrafficLight2_1_Pin, GPIO_PIN_SET);
			displayCounter();
			break;
		}
		if(isButtonPressed(2)) {
			status = TUNING_RED2;
			setTimer1(1000);
			timer_red1 = counter;
			if(timer_red1 <= timer_yellow2) timer_yellow2 = 1;
			timer_green2 = timer_red1 - timer_yellow2;
			counter = timer_red2;

			HAL_GPIO_WritePin(TrafficLight1_0_GPIO_Port, TrafficLight1_0_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(TrafficLight1_1_GPIO_Port, TrafficLight1_1_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(TrafficLight2_0_GPIO_Port, TrafficLight2_0_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(TrafficLight2_1_GPIO_Port, TrafficLight2_1_Pin, GPIO_PIN_RESET);
			displayCounter();
			break;
		}
		if(isButtonPressed(3)) {
			counter++;
			if(counter > 99) {
				counter = 2;
			}
			displayCounter();
		}
		break;
	case TUNING_RED2:
		if(timer1_flag==1) {
			timer1_flag = 0;
			setTimer1(1000);
			HAL_GPIO_TogglePin(TrafficLight2_0_GPIO_Port, TrafficLight2_0_Pin);
		}
		if(isButtonPressed(1)) {
			timer_red2 = counter;
			if(timer_red2 <= timer_yellow1) timer_yellow1 = 1;
			timer_green1 = timer_red2 - timer_yellow1;
			status = AUTO_RED_GREEN;
			setTimer1(1000);
			counter = timer_red1;

			HAL_GPIO_WritePin(TrafficLight1_0_GPIO_Port, TrafficLight1_0_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(TrafficLight1_1_GPIO_Port, TrafficLight1_1_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(TrafficLight2_0_GPIO_Port, TrafficLight2_0_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(TrafficLight2_1_GPIO_Port, TrafficLight2_1_Pin, GPIO_PIN_SET);
			displayCounter();
			break;
		}
		if(isButtonPressed(2)) {
			status = TUNING_GREEN1;
			setTimer1(1000);
			timer_red2 = counter;
			if(timer_red2 <= timer_yellow1) timer_yellow1 = 1;
			timer_green1 = timer_red2 - timer_yellow1;
			counter = timer_green1;

			HAL_GPIO_WritePin(TrafficLight1_0_GPIO_Port, TrafficLight1_0_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(TrafficLight1_1_GPIO_Port, TrafficLight1_1_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(TrafficLight2_0_GPIO_Port, TrafficLight2_0_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(TrafficLight2_1_GPIO_Port, TrafficLight2_1_Pin, GPIO_PIN_RESET);
			displayCounter();
			break;
		}
		if(isButtonPressed(3)) {
			counter++;
			if(counter > 99) {
				counter = 2;
			}
			displayCounter();
		}
		break;
	case TUNING_GREEN1:
		if(timer1_flag==1) {
			timer1_flag = 0;
			setTimer1(1000);
			HAL_GPIO_TogglePin(TrafficLight1_1_GPIO_Port, TrafficLight1_1_Pin);
		}
		if(isButtonPressed(1)) {
			timer_green1 = counter;
			timer_yellow1 = timer_red2 - timer_green1;
			status = AUTO_RED_GREEN;
			setTimer1(1000);
			counter = timer_red1;

			HAL_GPIO_WritePin(TrafficLight1_0_GPIO_Port, TrafficLight1_0_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(TrafficLight1_1_GPIO_Port, TrafficLight1_1_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(TrafficLight2_0_GPIO_Port, TrafficLight2_0_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(TrafficLight2_1_GPIO_Port, TrafficLight2_1_Pin, GPIO_PIN_SET);
			displayCounter();
			break;
		}
		if(isButtonPressed(2)) {
			status = TUNING_GREEN2;
			setTimer1(1000);
			timer_green1 = counter;
			timer_yellow1 = timer_red2 - timer_green1;
			counter = timer_green2;

			HAL_GPIO_WritePin(TrafficLight1_0_GPIO_Port, TrafficLight1_0_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(TrafficLight1_1_GPIO_Port, TrafficLight1_1_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(TrafficLight2_0_GPIO_Port, TrafficLight2_0_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(TrafficLight2_1_GPIO_Port, TrafficLight2_1_Pin, GPIO_PIN_RESET);
			displayCounter();
			break;
		}
		if(isButtonPressed(3)) {
			counter++;
			if(counter > timer_red2 - 1){
				counter = 1;
			}
			displayCounter();
		}
		break;
	case TUNING_GREEN2:
		if(timer1_flag==1) {
			timer1_flag = 0;
			setTimer1(1000);
			HAL_GPIO_TogglePin(TrafficLight2_1_GPIO_Port, TrafficLight2_1_Pin);
		}
		if(isButtonPressed(1)) {
			status = AUTO_RED_GREEN;
			timer_green2 = counter;
			timer_yellow2 = timer_red1 - timer_green2;
			setTimer1(1000);
			counter = timer_red1;

			HAL_GPIO_WritePin(TrafficLight1_0_GPIO_Port, TrafficLight1_0_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(TrafficLight1_1_GPIO_Port, TrafficLight1_1_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(TrafficLight2_0_GPIO_Port, TrafficLight2_0_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(TrafficLight2_1_GPIO_Port, TrafficLight2_1_Pin, GPIO_PIN_SET);
			displayCounter();
			break;
		}
		if(isButtonPressed(2)) {
			status = TUNING_YELLOW1;
			setTimer1(1000);
			timer_green2 = counter;
			timer_yellow2 = timer_red1 - timer_green2;
			counter = timer_yellow1;

			HAL_GPIO_WritePin(TrafficLight1_0_GPIO_Port, TrafficLight1_0_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(TrafficLight1_1_GPIO_Port, TrafficLight1_1_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(TrafficLight2_0_GPIO_Port, TrafficLight2_0_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(TrafficLight2_1_GPIO_Port, TrafficLight2_1_Pin, GPIO_PIN_RESET);
			displayCounter();
			break;
		}
		if(isButtonPressed(3)) {
			counter++;
			if(counter > timer_red1 - 1){
				counter = 1;
			}
			displayCounter();
		}
		break;
	case TUNING_YELLOW1:
		if(timer1_flag==1) {
			timer1_flag = 0;
			setTimer1(1000);
			HAL_GPIO_TogglePin(TrafficLight1_0_GPIO_Port, TrafficLight1_0_Pin);
			HAL_GPIO_TogglePin(TrafficLight1_1_GPIO_Port, TrafficLight1_1_Pin);
		}
		if(isButtonPressed(1)) {
			status = AUTO_RED_GREEN;
			timer_yellow1 = counter;
			timer_green1 = timer_red2 - timer_yellow1;
			setTimer1(1000);
			counter = timer_red1;

			HAL_GPIO_WritePin(TrafficLight1_0_GPIO_Port, TrafficLight1_0_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(TrafficLight1_1_GPIO_Port, TrafficLight1_1_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(TrafficLight2_0_GPIO_Port, TrafficLight2_0_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(TrafficLight2_1_GPIO_Port, TrafficLight2_1_Pin, GPIO_PIN_SET);
			displayCounter();
			break;
		}



		if(isButtonPressed(2)) {
			status = TUNING_YELLOW2;
			setTimer1(1000);
			timer_yellow1 = counter;
			timer_green1 = timer_red2 - timer_yellow1;
			counter = timer_yellow2;

			HAL_GPIO_WritePin(TrafficLight1_0_GPIO_Port, TrafficLight1_0_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(TrafficLight1_1_GPIO_Port, TrafficLight1_1_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(TrafficLight2_0_GPIO_Port, TrafficLight2_0_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(TrafficLight2_1_GPIO_Port, TrafficLight2_1_Pin, GPIO_PIN_RESET);
			displayCounter();
			break;
		}

		if(isButtonPressed(3)) {
			counter++;
			if(counter > timer_red2 - 1){
				counter = 1;
			}
			displayCounter();
		}
		break;
	case TUNING_YELLOW2:
		if(timer1_flag==1) {
			timer1_flag = 0;
			setTimer1(1000);
			HAL_GPIO_TogglePin(TrafficLight2_0_GPIO_Port, TrafficLight2_0_Pin);
			HAL_GPIO_TogglePin(TrafficLight2_1_GPIO_Port, TrafficLight2_1_Pin);
		}

		if(isButtonPressed(1)) {
			status = AUTO_RED_GREEN;
			timer_yellow2 = counter;
			timer_green2 = timer_red1 - timer_yellow2;
			setTimer1(1000);
			counter = timer_red1;

			HAL_GPIO_WritePin(TrafficLight1_0_GPIO_Port, TrafficLight1_0_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(TrafficLight1_1_GPIO_Port, TrafficLight1_1_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(TrafficLight2_0_GPIO_Port, TrafficLight2_0_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(TrafficLight2_1_GPIO_Port, TrafficLight2_1_Pin, GPIO_PIN_SET);
			displayCounter();
			break;
		}



		if(isButtonPressed(2)) {
			status = TUNING_RED1;
			setTimer1(1000);
			timer_yellow2 = counter;
			timer_green2 = timer_red1 - timer_yellow2;
			counter = timer_red1;

			HAL_GPIO_WritePin(TrafficLight1_0_GPIO_Port, TrafficLight1_0_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(TrafficLight1_1_GPIO_Port, TrafficLight1_1_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(TrafficLight2_0_GPIO_Port, TrafficLight2_0_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(TrafficLight2_1_GPIO_Port, TrafficLight2_1_Pin, GPIO_PIN_RESET);
			displayCounter();
			break;
		}

		if(isButtonPressed(3)) {
			counter++;
			if(counter > timer_red1 - 1){
				counter = 1;
			}
			displayCounter();
		}
		break;
	default:
		break;
	}
}
