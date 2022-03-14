#include<stdio.h>

int main()
{
    int number;
    printf("Enter a number: ");
    scanf("%d", &number);
    
    //15 is equal to 1111 in bits
    printf("Result of the 4 least significant bits: %d\n", (number & 15));
    return 0;
}
