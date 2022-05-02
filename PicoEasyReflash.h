#include "hardware/watchdog.h"

#ifdef EASY_REFLASH_NO_PAUSE
	#include "PicoBootsel.h"
#endif

int _bootsel_press_start = -1;

bool GetBOOTSEL(){
	#ifdef EASY_REFLASH_NO_PAUSE
		return get_bootsel_button();
	#else
		return BOOTSEL;
	#endif
}

void EasyReflashReset(){
	watchdog_enable(1, 1);
	while (1){
		//wait for watchdog reset.
	}
}

int TickBootselRead(){
	if (GetBOOTSEL()){
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