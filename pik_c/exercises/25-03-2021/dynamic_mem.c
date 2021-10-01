#include <stdio.h>
#include <stdlib.h>


void Task3();
void PrintArray(int *array3, unsigned length);

int main()
{  
    Task3();
    return 0;
}

void Task3()
{
    int n;
    printf("Enter size of arrays: ");
    scanf("%d", &n);
    int *array1, *array2, *array3;
    array1 = malloc(n*sizeof(int));
    array2 = malloc(n*sizeof(int));
    array3 = malloc(n*sizeof(int));

    printf("Enter items first array: \n");
    int i;
    for(i = 0; i < n; i++)
    {
        scanf("%d", &array1[i]);
    }

    printf("Enter items second array: \n");
    for(i = 0; i < n; i++)
    {
        scanf("%d", &array2[i]);
    }

    for(i = 0; i < n; i++)
    {
        array3[i] = array1[i] + array2[i];
    }

    PrintArray(array3, n);
    
    free(array1);
    free(array2);
    free(array3);
}

void PrintArray(int *array3, unsigned length)
{
    int i;
    for(i = 0; i < length; i++)
    {
        printf("array3[%d]: %d\n", i, array3[i]);
    }
}