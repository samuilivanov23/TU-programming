#include <stdio.h>
#include <stdlib.h>

void Task2();
void Task3();
void Task4();
void Task5();

int main()
{
    //Task2();
    //Task3();
    //Task4();
    //Task5();
}

void Task2()
{
    int size;
    scanf("%d\n", &size);
    char *text = (char*)malloc(size * sizeof(char));
    char * remain;
    fgets(text, size, stdin);
    puts(text);

    int i = 0;
    while(i < size)
    {
        if(text[i] == ' ')
        {
            break;
        }
        i++;
    }

    remain = (text + i + 1);
    puts(remain);
    free(text);
}

void Task3()
{
    int size;
    scanf("%d\n", &size);
    int *array1 = malloc(size * sizeof(int));
    int i;
    int second_size = 0;
    
    for (i = 0; i < size; i++)
    {
        scanf("%d", &array1[i]);
        if((array1[i] > 0) && (array1[i] % 5 == 0))
        {
            second_size++;
        }
    }

    int *array2 = malloc(second_size * sizeof(int));

    for(i = 0; i < second_size; i++)
    {
        if((array1[i] > 0) && (array1[i] % 5 == 0))
        {
            array2[i] = array1[i];
        }
    }

    for(i = 0; i < second_size; i++)
    {
        printf("%d\n", array2[i]);
    }

    free(array1);
    free(array2);
}

void Task4()
{
    int rows, cols;

    printf("rows: "),
    scanf("%d", &rows);

    printf("cols: "),
    scanf("%d", &cols);

    int *array = malloc(rows * cols * sizeof(int));

    int i,j;
    for(i = 0; i < rows; i++)
    {
        for(j = 0; j < cols; j++)
        {
            scanf("%d", &array[i*cols + j]); //array[i][j]
            printf("%d\n", array[i*cols + j]);
        }
    }


    int sum = 0;
    int current_sum = 0;

    for(j = 0; j < cols; j++)
    {
        for(i = 0; i < rows; i++)
        {
            sum += array[j*cols + i]; //array[j][i]

            if(current_sum < sum)
            {
                current_sum = sum;
            }
        }

        sum = 0;
    }

    printf("max sum: %d\n", current_sum);
}

void Task5()
{
    int size = 0;
    char *text = (char*)malloc(sizeof(char));
    char c;

    while((c = getchar()) != EOF)
    {
        text[size] = c;
        size++;
        text = realloc(text, size + sizeof(char));
    }

    text[size+1] = '\0';
    puts(text);
    free(text);
}