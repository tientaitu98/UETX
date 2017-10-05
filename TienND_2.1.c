/* Include header */
#include <stdio.h>
#include <stdint.h>
#include <math.h>
/* Macro MAX */
#define MAX 100

void input(float m[], float *r, float *c);
void sum(float m1[], int8_t r1, int8_t c1, float m2[], int8_t r2, int8_t c2);
void multi(float m1[], int8_t r1, int8_t c1, float m2[], int8_t r2, int8_t c2);
void task(float m1[], int8_t r1, int8_t c1, float m2[], int8_t r2, int8_t c2);
int main()
{
    /* Input matrix A */
    float r1;
    float m1[MAX];
    float c1;
    printf("Matrix A:\n");
    input(m1, &r1, &c1);
    /* Input matrix B */
    float r2;
    float m2[MAX];
    float c2;
    printf("Matrix B:\n");
    input(m2, &r2, &c2);
    /* Addition two matrices */
    sum(m1, r1, c1, m2, r2, c2);
    printf("\n");
    /* Multiplication two matrices */
    multi(m1, r1, c1, m2, r2, c2);
    return 0;
}
/* Input */
void input(float m[], float *r, float *c)
{
    /* Check the row value satisfies */
    float val;
    do
    {
        printf("Input row of matrix: ");
        scanf("%f", &(*r));
        val = *r - floor(*r);
        if(*r <= 0 || val > 0)
        {
            printf("Wrong input. Try again!\n");
        }
    }while(*r <= 0 || val > 0);
    /* Check the column value satisfies */
    do
    {
        printf("Input column of matrix: ");
        scanf("%f", &(*c));
        val = *c - floor(*c);
        if(*c <= 0 || val > 0)
        {
            printf("Wrong input. Try again!\n");
        }
    }while(*c <= 0 || val > 0);
    /* Enter value */
    int8_t i;
    for(i = 0; i < (*r) * (*c); i++)
    {
        scanf("%f", &m[i]);
    }
    printf("\n");
}
/* Two matrices addition */
void sum(float m1[], int8_t r1, int8_t c1, float m2[], int8_t r2, int8_t c2)
{
    /* Check the condition of two matrices addition */
    if(((r1 == c1) && (r1 == 1)) || ((r2 == c2) && (r2 == 1)))
    {
        printf("Can't addition two matrices!");
    }
    else if((r1 != r2) || (c1 != c2))
    {
        printf("Can't addition two matrices!");
    }
    /* Result */
    else
    {
        int8_t i;
        printf("A + B:\n");
        for(i = 0; i < r1 * c1; i++)
        {
            printf("%.2f ", m1[i] + m2[i]);
            if((i + 1 ) % c1 == 0)
            {
                printf("\n");
            }
        }
    }
    printf("\n");
}
/* Two matrices multiplication */
void multi(float m1[], int8_t r1, int8_t c1, float m2[], int8_t r2, int8_t c2)
{
    /* Check the condition of two matrices multiplication */
    if(((r1 == c1) && (r1 == 1)) || ((r2 == c2) && (r2 == 1)))
    {
        printf("Can't mutiplication two matrices!");
    }
    if(c1 == r2)
    {
        printf("A x B:\n");
        task(m1, r1, c1, m2, r2, c2);
    }
    if(r1 == c2)
    {
        printf("B x A:\n");
        task(m2, r2, c2, m1, r1, c1);
    }
    else
    {
        printf("Can't mutiplication two matrices!");
    }
}
void task(float m1[], int8_t r1, int8_t c1, float m2[], int8_t r2, int8_t c2)
{
    float tempm[MAX];
        int8_t sum;
        /* multiplication two matrices */
        int8_t i;
        for(i = 0; i < r1; i++)
        {
            int8_t j;
            for(j = 0; j < c2; j++)
            {
                sum = 0;
                int8_t k;
                for(k = 0; k < r2; k++)
                {
                    sum += m1[i * c1 + k] * m2[k * c2 + j];
                    tempm[i * c2 + j] = sum;
                }
            }
        }
        /* Result */
        for(i = 0; i < r1 * c2; i++)
        {
            printf("%.2f ", tempm[i]);
            if((i + 1 ) % c2 == 0)
            {
                printf("\n");
            }
        }
}