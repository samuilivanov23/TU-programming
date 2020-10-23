#include<stdio.h>

int sum();
double average();

int main()
{
    printf("Sum: %d\n", sum());
    printf("Average: %.3f\n", average());
    return 0;
}

int sum()
{
    int number;
    int sum = 0;
    do
    {
        printf("Eneter number: ");
        scanf("%d", &number);
        sum += number;
    }
    while(number != 0);

    return sum;
}

double average()
{
    int number;
    int sum = 0;
    int numbers_count = 0;
    do
    {
        printf("Eneter number: ");
        scanf("%d", &number);
        sum += number;
        numbers_count+=1;
    }
    while(number != 0);

    return (double)sum/(numbers_count-1);
}