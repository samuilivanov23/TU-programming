#include<stdio.h>

int main()
{
    int number1, number2;
    printf("Enter first number: ");
    scanf("%d", &number1);
    printf("Enter second number: ");
    scanf("%d", &number2);
    
    number1 = number1 ^ number2;
    number2 = number1 ^ number2;
    number1 = number1 ^ number2;
    
    printf("First number is: %d\n", number1);
    printf("Second number is: %d\n", number2);
    return 0;
}
