#include "fsm_pedestrian.h"
int PWM = 0;
void fsm_pedestrian_run() {
	switch(pedestrianStatus) {
		case INIT:
			HAL_GPIO_WritePin(PedestrianLight_0_GPIO_Port, PedestrianLight_0_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(PedestrianLight_1_GPIO_Port, PedestrianLight_1_Pin, GPIO_PIN_RESET);
			pedestrianStatus = PED_NONE;
			break;
		case PED_NONE:
			if(isButtonPressed(0)) {
				if(status == AUTO_RED_GREEN || status == AUTO_RED_YELLOW) {
					pedestrianStatus = PED_GREEN;
					HAL_GPIO_WritePin(PedestrianLight_0_GPIO_Port, PedestrianLight_0_Pin, GPIO_PIN_RESET);
					HAL_GPIO_WritePin(PedestrianLight_1_GPIO_Port, PedestrianLight_1_Pin, GPIO_PIN_SET);
					setTimer2(250);
				}else if(status == MAN_RED_GREEN || status == MAN_RED_YELLOW ) {
					pedestrianStatus = PED_GREEN;
					HAL_GPIO_WritePin(PedestrianLight_0_GPIO_Port, PedestrianLight_0_Pin, GPIO_PIN_RESET);
					HAL_GPIO_WritePin(PedestrianLight_1_GPIO_Port, PedestrianLight_1_Pin, GPIO_PIN_SET);
					setTimer2(0);
				}
				else if(status == AUTO_GREEN_RED || status == MAN_GREEN_RED || status == AUTO_YELLOW_RED || status == MAN_YELLOW_RED){
					pedestrianStatus = PED_RED;
					HAL_GPIO_WritePin(PedestrianLight_0_GPIO_Port, PedestrianLight_0_Pin, GPIO_PIN_SET);
					HAL_GPIO_WritePin(PedestrianLight_1_GPIO_Port, PedestrianLight_1_Pin, GPIO_PIN_RESET);
				}
			}
			break;
		case PED_RED:
			if(timer3_flag==1) {
				timer3_flag = 0;
				pedestrianStatus = PED_NONE;
				HAL_GPIO_WritePin(PedestrianLight_0_GPIO_Port, PedestrianLight_0_Pin, GPIO_PIN_RESET);
				HAL_GPIO_WritePin(PedestrianLight_1_GPIO_Port, PedestrianLight_1_Pin, GPIO_PIN_RESET);
				break;
			}
			else if(status == AUTO_RED_GREEN) {
				pedestrianStatus = PED_GREEN;
				HAL_GPIO_WritePin(PedestrianLight_0_GPIO_Port, PedestrianLight_0_Pin, GPIO_PIN_RESET);
				HAL_GPIO_WritePin(PedestrianLight_1_GPIO_Port, PedestrianLight_1_Pin, GPIO_PIN_SET);
				setTimer2(250);
			}
			else if (status == MAN_RED_GREEN) {
				pedestrianStatus = PED_GREEN;
				HAL_GPIO_WritePin(PedestrianLight_0_GPIO_Port, PedestrianLight_0_Pin, GPIO_PIN_RESET);
				HAL_GPIO_WritePin(PedestrianLight_1_GPIO_Port, PedestrianLight_1_Pin, GPIO_PIN_SET);
				setTimer2(0);
			}
			break;
		case PED_GREEN:
			if(timer2_flag==1) {
				if(PWM == 0) {
					PWM = 63-63*counter/timer_red1;
					__HAL_TIM_SetCompare(&htim3, TIM_CHANNEL_1,PWM);
				} else {
					PWM = 0;
					__HAL_TIM_SetCompare(&htim3, TIM_CHANNEL_1,PWM);
				}
				setTimer2(250);
			}
			if(status == AUTO_GREEN_RED || status == MAN_GREEN_RED || status == AUTO_YELLOW_RED || status == MAN_YELLOW_RED) {
				pedestrianStatus = PED_RED;
				setTimer3(2000);
				HAL_GPIO_WritePin(PedestrianLight_0_GPIO_Port, PedestrianLight_0_Pin, GPIO_PIN_SET);
				HAL_GPIO_WritePin(PedestrianLight_1_GPIO_Port, PedestrianLight_1_Pin, GPIO_PIN_RESET);
				__HAL_TIM_SetCompare(&htim3, TIM_CHANNEL_1,0);
			}
			break;
		default:
			break;
	}
}
