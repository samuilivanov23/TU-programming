#include <stdio.h>
#include <stdlib.h>

int main()
{
    //int 2-4 bytes
    //float - 4 byte
    //double - 4 byte
    //char - 1 byte

    int *array = (int*)malloc(5 * sizeof(int));

    for(int i = 0; i < 5; i++)
    {
        printf("Enter number: ");
        scanf("%d", &array[i]);
    }

    for(int i = 0; i < 5; i++)
    {
        printf("array[%d]: %d\n", i, array[i]);
    }

    getchar();
    int text_size = 5;
    char *text = (char*)malloc((text_size + 1) * sizeof(char));
    fgets(text, (text_size + 1), stdin);
    puts(text);
}