#include <stdio.h>

int main()
{
    double num;
    printf("Enter num: ");
    scanf("%lf", &num);

    double max = num;

    do
    {
        printf("Enter num: ");
        scanf("%le", &num);

        if (num > max)
        {
            max = num;
        }
    }while(num != 0);

    printf("max: %f\n", max);
    return 0;
}