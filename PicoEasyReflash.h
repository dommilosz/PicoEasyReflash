#include "hardware/watchdog.h"

int _bootsel_press_start = -1;

void EasyReflashReset(){
	watchdog_enable(1, 1);
	while (1){
		//wait for watchdog reset.
	}
}

int TickBootselRead(){
	if (BOOTSEL){
		if(_bootsel_press_start < 0)_bootsel_press_start = millis();
		int duration = millis()-_bootsel_press_start;
		if(duration>1000){
			return 1;
		}
	}else{
		if(_bootsel_press_start > 0){
			int duration = millis()-_bootsel_press_start;
			if(duration>50){
				return 0;
			}
		}
	}
	return -1;
}

void TickEasyReflash()
{
	int r = TickBootselRead();
	if (r != -1)
	{
		EasyReflashReset();
	}
}