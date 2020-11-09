#include <stdio.h>

int main()
{
    int num;
    printf("Enter num: ");
    scanf("%d", &num);

    int multiplication = 1;

    if((num % 3) == 0)
    {
        multiplication *= num;
    }

    do
    {
        printf("Enter num: ");
        scanf("%d", &num);
        if ((num % 3) == 0 && num != 0)
        {
            multiplication *= num;
        }
    }while(num != 0);

    if(multiplication == 1)
    {
        printf("No divisible numbers by 3\n");
    }
    else
    {
        printf("multiplication: %d\n", multiplication);
    }
    return 0;
}