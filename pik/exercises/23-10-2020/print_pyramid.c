#include <stdio.h>

int main()
{
    int size;
    printf("Enter size: ");
    scanf("%d", &size);

    int i = size;
    for (; i > 0; i--)
    {
        int j = 0;
        for (; j < i; j++)
        {
            printf("*");
        }
        printf("\n");
    }
    return 0;
}