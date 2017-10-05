/* Include header */
#include <stdio.h>
#include <stdint.h>
#include <math.h>
int main()
{
    float n;
    float val;
    printf("S = 1/2 + 3/4 + 5/6 + ... + (2n+1)/(2n+2)\n");
    do
    {
        printf("Input n: ");
        scanf("%f", &n);
        val = n - floor(n);
        if(n < 0 || val > 0)
        {
            printf("Wrong input. Try again!\n");
        }
        else
        {
            float sum = 0;
            float i;
            for(i = 0; i <= n; i++)
            {
                sum = sum + ((2 * i + 1) / (2 * i + 2));
            }
            printf("S = %g", sum);
        }
    }while(n < 0 || val > 0);
    return 0;
}