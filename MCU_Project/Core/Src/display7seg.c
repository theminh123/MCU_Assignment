#include "display7seg.h"

//Display the counter using UART
void displayCounter() {
	sprintf(str, "!7SEG:%d%d#\r\n", counter/10, counter%10);//TENS = Counter/10 ; UNITS = Counter%10
	HAL_UART_Transmit_IT(&huart2, (void*)str, 15);
}
