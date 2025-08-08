#include "main.h"
#include <stdio.h>

int main(void)
{
	int r;

	r = _isalpha('H');
	printf("%d\n", r);
	r = _isalpha('o');
	printf("%d\n", r);
	r = _isalpha(108);
	printf("%d\n", r);
	r = _isalpha(';');
	printf("%d\n", r);
	return (0);
}
