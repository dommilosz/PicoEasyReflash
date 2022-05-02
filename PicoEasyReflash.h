#include "PicoBootsel.h"
#include "hardware/watchdog.h"

int CheckRestart()
{
	if (get_bootsel_button())
	{
		int start = millis();
		while (get_bootsel_button())
		{
			if ((millis() - start) > 1000)
			{
				return 0;
			}
			delay(50);
			watchdog_update();
		}
		delay(50);
		return 1;
	}
	return -1;
}

void PerformRestart()
{
	int r = CheckRestart();
	if (r != -1)
	{
		watchdog_enable(1, 1);
		while (1)
		{
		};
	}
}