#include "mode.h"
#include "fsm_auto.h"
#include "fsm_manual.h"
#include "fsm_pedestrian.h"
#include "fsm_tuning.h"

void mode_run() {
	switch(mode) {
	case 1:
		fsm_automatic(); //AUTOMATIK
	case 2:
		fsm_manual(); //MANUAL MODE
	case 3:
		fsm_tuning(); //TWEAK THE TIMING
	}
}

