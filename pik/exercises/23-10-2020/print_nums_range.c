#include <stdio.h>

void printNums(int num1, int num2);

int main()
{
    int num1;
    int num2;
    
    printf("Enter num1: ");
    scanf("%d", &num1);

    printf("Enter num2: ");
    scanf("%d", &num2);

    if(num1 <= num2)
    {
        printNums(num1, num2);
    }
    else
    {
        printNums(num2, num1);
    }

    return 0;
}

void printNums(int num1, int num2)
{
    int i = num1;
    for(; i <= num2; i++)
    {
        printf("%d\n", i);
    }
}