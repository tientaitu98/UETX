/* Include header */
#include <stdio.h>
#include <stdint.h>
#include <math.h>

int main()
{
    float val;
    float n;
    printf("S = 1^3 + 2^3 + ... + n^3\n");
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
            float result;
            result = pow(((n * (n + 1)) / 2), 2);
            printf("S = %.0f", result);
        }
    }while(n < 0 || val > 0);
    return 0;
}