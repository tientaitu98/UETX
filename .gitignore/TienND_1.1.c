/* Include header */
#include<stdio.h>
#include<stdint.h>
/* Macro Max=100*/
#define Max 100
/* Swap two numbers function */
void swapNumber(int Array[],uint8_t i,uint8_t j)
{
    Array[i]=Array[i]+Array[j];
    Array[j]=Array[i]-Array[j];
    Array[i]=Array[i]-Array[j];
}
/* Output function */
void output(int Array[], uint8_t length)
{
    for(uint8_t i=0;i<length;i++)
    {
        printf("%d ",Array[i]);
    }
}
/* Bubblesort function */
void bubbleSort(int Array[],uint8_t length)
{
    for (uint8_t i=0;i<length;i++)
    {
        for (uint8_t j=i+1;j<length;j++)
        {
            if(Array[i] > Array[j])
            {
                swapNumber(Array,i,j);
            }
        }
    }
}
/* This function transfers values from array A to array B with the same in length */
void transferArray(int tempArray[],int Array[],uint8_t length)
{
    for(uint8_t i=0;i<length;i++)
    {
        Array[i]=tempArray[i];
    }
}
/* In this function, we put odd numbers to the left, even numbers to the right */
void sortNumber(int Array[],uint8_t length)
{
    /* BubbleSort first */
    bubbleSort(Array,length);
    int tempArray[length];
    uint8_t tempCount=0;
    /* Put the odd numbers to temporary array first*/
    for(uint8_t i=0;i<length;i++)
    {
        if(Array[i]%2!=0)
        {
            tempArray[tempCount]=Array[i];
            tempCount++;
        }
    }
    /* Then put the even numbers to temporary array */
    for(uint8_t i=length-1;i>0;i--)
    {
        if(Array[i]%2==0)
        {
            tempArray[tempCount]=Array[i];
            tempCount++;
        }
    }
    /* Transfer value in temporary array to main Array */
    transferArray(tempArray,Array,length);
    /* Print to the screen */
    output(Array,length);
}
/* This function sums the numbers in the odd/even position of the array */
void sum(int Array[],uint8_t length)
{
    /* Set 0 is the first value of tempSum*/
    int tempSum=0;
    for(uint8_t i=0;i<length;i+=2)
    {
        tempSum+=Array[i];
    }
    /* Print to the screen */
    printf("%d ",tempSum);
    /* Reset the value of tempSum to 0 */
    tempSum=0;
    for(uint8_t i=1;i<length;i+=2)
    {
        tempSum+=Array[i];
    }
    printf("%d",tempSum);
}
/* Main function */
int main()
{
    int Array[Max];
    uint8_t length;
    /* Get the length the array from the kerboard */
    scanf("%d",&length);
    /* Get the values of the array in turn from the keyboard */
    for (uint8_t i=0;i<length;i++)
    {
        scanf("%d",&Array[i]);
    }
    /* Sorting */
    sortNumber(Array,length);
    /* After sorting, calculate the sum */
    sum(Array,length);
    return 0;
}
