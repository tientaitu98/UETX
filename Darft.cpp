#include <stdio.h>
#include <stdint.h>
#include <math.h>

int main()
{
	float i;
	scanf("%f", &i);
	if (i - floor(i) > 0);
	{
		printf("%.1f", i);
		printf("Wrong input. Try again!\n");
	}
	return 0;
}

