#include "main.h"
#include <stdio.h>

int main(void)
{
	int r;

	r = _islower('H');
	printf("%d\n", r);  // 0
	r = _islower('o');
	printf("%d\n", r);  // 1
	return (0);
}
