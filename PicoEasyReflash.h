#include "hardware/watchdog.h"

#ifndef EASY_REFLASH_DISABLE_BOOTLOADER_RESET
#include "pico/bootrom.h"
#endif

#ifdef EASY_REFLASH_NO_PAUSE
#include "PicoBootsel.h"
#endif

int _bootsel_press_start = -1;
int _short_press_duration_min = 50;
int _long_press_duration_min = 1000;
typedef void (*bootsel_read_callback_t)(int duration, bool holding);

bool GetBOOTSEL()
{
#ifdef EASY_REFLASH_NO_PAUSE
	return get_bootsel_button();
#else
	return BOOTSEL;
#endif
}

void EasyReflashReset()
{
	watchdog_enable(1, 1);
	while (1)
	{
		//wait for watchdog reset.
	}
}

void EasyReflashResetBootloader()
{
#ifdef EASY_REFLASH_DISABLE_BOOTLOADER_RESET
#error EasyReflashResetBootloader is Disabled when EASY_REFLASH_DISABLE_BOOTLOADER_RESET is defined.
#else
	reset_usb_boot(
		0u,
		0u);
#endif
}

int TickBootselRead(bool *holding = 0)
{
	if (GetBOOTSEL())
	{
		if (_bootsel_press_start < 0)
			_bootsel_press_start = millis();
		int duration = millis() - _bootsel_press_start;
		if (holding != 0)
			*holding = true;
		return duration;
	}
	else
	{
		if (_bootsel_press_start > 0)
		{
			int duration = millis() - _bootsel_press_start;
			if (holding != 0)
				*holding = false;

			_bootsel_press_start = -1;
			return duration;
		}
	}
	return -1;
}

void DefaultEasyReflashCallback(int duration, bool holding)
{
	if (holding && duration > _long_press_duration_min)
	{
		EasyReflashReset();
	}
	if (!holding && duration > _short_press_duration_min)
	{
		EasyReflashReset();
	}
}

bootsel_read_callback_t bootsel_read_callback = DefaultEasyReflashCallback;

void TickEasyReflash()
{
	bool holding = false;
	int duration = TickBootselRead(&holding);
	if (duration != -1)
	{
		bootsel_read_callback(duration, holding);
	}
}

void EasyReflashSetDelays(int reset = 50, int bootloader = 1000)
{
	_short_press_duration_min = reset;
	_long_press_duration_min = bootloader;
}
void EasyReflashSetCallback(bootsel_read_callback_t cb = DefaultEasyReflashCallback)
{
	bootsel_read_callback = cb;
}