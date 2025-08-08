#include "main.h"

/**
 * jack_bauer - Prints every minute of the day of Jack Bauer
 *
 * Description: Prints every minute from 00:00 to 23:59.
 *
 */
{
	int hour, minute;

	for (hour = 0; hour < 24; hour++)
	{
		for (minute = 0; minute < 60; minute++)
		{
			_putchar(hour / 10 + '0');
			_putchar(hour % 10  + '0');
			_putchar(':');
			_putchar(minute / 10 + '0');
			_putchar(minute % 10 + '0');
			_putchar('\n');
		}
	}
}
