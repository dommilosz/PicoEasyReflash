#include "hardware/watchdog.h"

#ifdef EASY_REFLASH_NO_PAUSE
	#include "PicoBootsel.h"
#endif

int _bootsel_press_start = -1;
int _short_press_duration_min = 50;
int _long_press_duration_min = 1000;
bool _reversed_timings = false;

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
		if(duration>_long_press_duration_min){
			return 1;
		}
	}else{
		if(_bootsel_press_start > 0){
			int duration = millis()-_bootsel_press_start;
			if(duration>_short_press_duration_min){
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

void EasyReflashSetDelays(int reset=50, int bootloader=1000){
	_short_press_duration_min = reset;
	_long_press_duration_min = bootloader;
}