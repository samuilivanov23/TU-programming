#include <stdio.h>

int main() {
    int i, j, rows;

    printf("Enter the number of rows: ");
    scanf("%d", &rows);

    int starting_number;
    printf("Enter starting number: ");
    scanf("%d", &starting_number);

    if(rows > 0)
    {
        for (i = 1; i <= rows; ++i) 
        {
            for (j = 1; j <= i; ++j) 
            {
                printf("%d ", starting_number);
            }

            starting_number++;

            printf("\n");
        }
    }

    return 0;
}