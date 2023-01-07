#include "main.h"
#include "mode.h"
#include "change_mode.h"

//INIT
enum ButtonState {BUTTON_RELEASED, BUTTON1_PRESSED} ;
enum ButtonState buttonState = BUTTON_RELEASED;

void mode_selector(void) {
	switch (buttonState) {
		 case BUTTON_RELEASED :
			 if(isButtonPressed(1)) {
				 buttonState = BUTTON1_PRESSED;
				 mode++;
			 }
			 break;
		 case BUTTON1_PRESSED :
			 if (!isButtonPressed(1)) {
				 buttonState = BUTTON_RELEASED;
			 }
			 if(mode == 2) {
				status = MAN_RED_GREEN;
				setTimer1(60000);
				counter = 99;

				HAL_GPIO_WritePin(TrafficLight1_0_GPIO_Port, TrafficLight1_0_Pin, GPIO_PIN_SET);
				HAL_GPIO_WritePin(TrafficLight1_1_GPIO_Port, TrafficLight1_1_Pin, GPIO_PIN_RESET);
				HAL_GPIO_WritePin(TrafficLight2_0_GPIO_Port, TrafficLight2_0_Pin, GPIO_PIN_RESET);
				HAL_GPIO_WritePin(TrafficLight2_1_GPIO_Port, TrafficLight2_1_Pin, GPIO_PIN_SET);
				displayCounter();
			 }
			 if(mode == 3){
				status = TUNING_RED1;
				setTimer1(1000);
				counter = timer_red1;

				HAL_GPIO_WritePin(TrafficLight1_0_GPIO_Port, TrafficLight1_0_Pin, GPIO_PIN_RESET);
				HAL_GPIO_WritePin(TrafficLight1_1_GPIO_Port, TrafficLight1_1_Pin, GPIO_PIN_RESET);
				HAL_GPIO_WritePin(TrafficLight2_0_GPIO_Port, TrafficLight2_0_Pin, GPIO_PIN_RESET);
				HAL_GPIO_WritePin(TrafficLight2_1_GPIO_Port, TrafficLight2_1_Pin, GPIO_PIN_RESET);
				displayCounter();
			 }
			 if(mode > 3){
			 	mode = 1; //RESET MODE CYLCE
			 }
			 break;
		}
}
