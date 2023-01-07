#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

#include "display7seg.h"
#include "timer.h"
#include "main.h"
#include "button.h"

//STATUS
extern int status;
extern int pedestrianStatus;
extern int counter;

//FLAGS
extern int ped_red_flag;
extern int ped_green_flag;

//MODE
extern int mode;

//PEDESTRIAN LIGHTS
#define	PED_NONE	2
#define PED_RED		3
#define PED_GREEN	4

//CASE OF AVTOMAT 3LIGHTS
#define	INIT			1 //4STATE+1INIT = INIT R-G R-Y G-R Y-R
#define	AUTO_RED_GREEN	2
#define	AUTO_RED_YELLOW	3
#define	AUTO_GREEN_RED	4
#define	AUTO_YELLOW_RED	5

//CASE OF MANUAL 3LIGHTS
#define	MAN_RED_GREEN	11 //4STATE = R-G R-Y G-R Y-R
#define	MAN_RED_YELLOW	12
#define	MAN_GREEN_RED	13
#define	MAN_YELLOW_RED	14

//CASE OF TWEAKING THE TIMING
#define	TUNING_RED1		21
#define	TUNING_RED2		22
#define	TUNING_GREEN1	23
#define	TUNING_GREEN2	24
#define	TUNING_YELLOW1	25
#define	TUNING_YELLOW2	26

//TIMER FOR EACH LIGHTS
extern int timer_red1;
extern int timer_green1;
extern int timer_yellow1;

extern int timer_red2;
extern int timer_green2;
extern int timer_yellow2;

//OUTPUT STRING
extern char str[];

#endif /* INC_GLOBAL_H_ */
