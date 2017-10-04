/* Include header */
#include <stdio.h>
#include <stdint.h>
#include <math.h>

int main()
{
	float sum;
	float i;
	scanf("%f", &i);
	printf("%.2f\n",i);
	if ((i - floor(i)) > 0);
	{
		printf("Wrong input. Try again!\n");
	}
	sum = pow((i * (i+1))/2,2);
	printf("%.2f", sum);
	return 0;
}
