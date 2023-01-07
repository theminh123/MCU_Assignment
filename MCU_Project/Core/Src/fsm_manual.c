#include "fsm_manual.h"

void fsm_manual() {
	switch(status) {
		case MAN_RED_GREEN:
			isButtonPressed(3);
			if(timer1_flag==1) {
				status = AUTO_RED_YELLOW;
				setTimer1(1000);
				counter = timer_yellow2;
				displayCounter();

				HAL_GPIO_WritePin(TrafficLight1_0_GPIO_Port, TrafficLight1_0_Pin, GPIO_PIN_SET);
				HAL_GPIO_WritePin(TrafficLight1_1_GPIO_Port, TrafficLight1_1_Pin, GPIO_PIN_RESET);
				HAL_GPIO_WritePin(TrafficLight2_0_GPIO_Port, TrafficLight2_0_Pin, GPIO_PIN_SET);
				HAL_GPIO_WritePin(TrafficLight2_1_GPIO_Port, TrafficLight2_1_Pin, GPIO_PIN_SET);
			}

			if (isButtonPressed(2)) {
				status = MAN_RED_YELLOW;
				HAL_GPIO_WritePin(TrafficLight1_0_GPIO_Port, TrafficLight1_0_Pin, GPIO_PIN_SET);
				HAL_GPIO_WritePin(TrafficLight1_1_GPIO_Port, TrafficLight1_1_Pin, GPIO_PIN_RESET);
				HAL_GPIO_WritePin(TrafficLight2_0_GPIO_Port, TrafficLight2_0_Pin, GPIO_PIN_SET);
				HAL_GPIO_WritePin(TrafficLight2_1_GPIO_Port, TrafficLight2_1_Pin, GPIO_PIN_SET);
				setTimer1(60000);
			}
			break;
		case MAN_RED_YELLOW:
			if(timer1_flag==1) {
				status = AUTO_GREEN_RED;
				setTimer1(1000);
				counter = timer_green1;
				displayCounter();
				HAL_GPIO_WritePin(TrafficLight1_0_GPIO_Port, TrafficLight1_0_Pin, GPIO_PIN_RESET);
				HAL_GPIO_WritePin(TrafficLight1_1_GPIO_Port, TrafficLight1_1_Pin, GPIO_PIN_SET);
				HAL_GPIO_WritePin(TrafficLight2_0_GPIO_Port, TrafficLight2_0_Pin, GPIO_PIN_SET);
				HAL_GPIO_WritePin(TrafficLight2_1_GPIO_Port, TrafficLight2_1_Pin, GPIO_PIN_RESET);
			}

			if (isButtonPressed(2)) {
				status = MAN_GREEN_RED;
				HAL_GPIO_WritePin(TrafficLight1_0_GPIO_Port, TrafficLight1_0_Pin, GPIO_PIN_RESET);
				HAL_GPIO_WritePin(TrafficLight1_1_GPIO_Port, TrafficLight1_1_Pin, GPIO_PIN_SET);
				HAL_GPIO_WritePin(TrafficLight2_0_GPIO_Port, TrafficLight2_0_Pin, GPIO_PIN_SET);
				HAL_GPIO_WritePin(TrafficLight2_1_GPIO_Port, TrafficLight2_1_Pin, GPIO_PIN_RESET);
				setTimer1(60000);
			}
			break;
		case MAN_GREEN_RED:
			if(timer1_flag==1) {
				status = AUTO_YELLOW_RED;
				setTimer1(1000);
				counter = timer_yellow1;
				displayCounter();
				HAL_GPIO_WritePin(TrafficLight1_0_GPIO_Port, TrafficLight1_0_Pin, GPIO_PIN_SET);
				HAL_GPIO_WritePin(TrafficLight1_1_GPIO_Port, TrafficLight1_1_Pin, GPIO_PIN_SET);
				HAL_GPIO_WritePin(TrafficLight2_0_GPIO_Port, TrafficLight2_0_Pin, GPIO_PIN_SET);
				HAL_GPIO_WritePin(TrafficLight2_1_GPIO_Port, TrafficLight2_1_Pin, GPIO_PIN_RESET);

			}

			if (isButtonPressed(2)) {
				status = MAN_YELLOW_RED;
				HAL_GPIO_WritePin(TrafficLight1_0_GPIO_Port, TrafficLight1_0_Pin, GPIO_PIN_SET);
				HAL_GPIO_WritePin(TrafficLight1_1_GPIO_Port, TrafficLight1_1_Pin, GPIO_PIN_SET);
				HAL_GPIO_WritePin(TrafficLight2_0_GPIO_Port, TrafficLight2_0_Pin, GPIO_PIN_SET);
				HAL_GPIO_WritePin(TrafficLight2_1_GPIO_Port, TrafficLight2_1_Pin, GPIO_PIN_RESET);
				setTimer1(60000);
			}
			break;
		case MAN_YELLOW_RED:
			if(timer1_flag==1) {
				status = AUTO_RED_GREEN;
				setTimer1(1000);
				counter = timer_red1;
				displayCounter();
				HAL_GPIO_WritePin(TrafficLight1_0_GPIO_Port, TrafficLight1_0_Pin, GPIO_PIN_SET);
				HAL_GPIO_WritePin(TrafficLight1_1_GPIO_Port, TrafficLight1_1_Pin, GPIO_PIN_RESET);
				HAL_GPIO_WritePin(TrafficLight2_0_GPIO_Port, TrafficLight2_0_Pin, GPIO_PIN_RESET);
				HAL_GPIO_WritePin(TrafficLight2_1_GPIO_Port, TrafficLight2_1_Pin, GPIO_PIN_SET);
			}

			if (isButtonPressed(2)) {
				status = MAN_RED_GREEN;
				HAL_GPIO_WritePin(TrafficLight1_0_GPIO_Port, TrafficLight1_0_Pin, GPIO_PIN_SET);
				HAL_GPIO_WritePin(TrafficLight1_1_GPIO_Port, TrafficLight1_1_Pin, GPIO_PIN_RESET);
				HAL_GPIO_WritePin(TrafficLight2_0_GPIO_Port, TrafficLight2_0_Pin, GPIO_PIN_RESET);
				HAL_GPIO_WritePin(TrafficLight2_1_GPIO_Port, TrafficLight2_1_Pin, GPIO_PIN_SET);
				setTimer1(60000);
			}
			break;
		default: //DO NOTHING
			break;
	}
}

