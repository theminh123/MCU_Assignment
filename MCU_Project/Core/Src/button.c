#include "button.h"

//Button buffer
static int button_buffer[NUMBER_BUTTONS];

static int db_1[NUMBER_BUTTONS];
static int db_2[NUMBER_BUTTONS];
static int db_3[NUMBER_BUTTONS];

//Array to find which button
static int button_flag[NUMBER_BUTTONS];

//RESET FLAG
int isButtonPressed(int index){
	if(button_flag[index] == 1){
		button_flag[index] = 0;
		return 1;
	}
	return 0;
}

//READ BUTTON
void button_processing(){
	for(uint8_t i = 0 ; i < NUMBER_BUTTONS; i++){
        //Debounce
		db_3[i] = db_2[i];
		db_2[i] = db_1[i];
		//DO STH

		if(i == 0) db_1[i] = HAL_GPIO_ReadPin(PedestrianButton_GPIO_Port, PedestrianButton_Pin);
		else if(i == 1) db_1[i] = HAL_GPIO_ReadPin(Button1_GPIO_Port, Button1_Pin);
		else if(i == 2) db_1[i] = HAL_GPIO_ReadPin(Button2_GPIO_Port, Button2_Pin);
		else if(i == 3) db_1[i] = HAL_GPIO_ReadPin(Button3_GPIO_Port, Button3_Pin);

        //DO AFTER DEBOUNCE
		if((db_3[i] == db_2[i]) && db_2[i] == db_1[i]){
			button_buffer[i] = db_3[i];
		}
	}
}


