#include <stdio.h>
#include <stdlib.h>

void CoppyArray(int *source, int **destination, unsigned size);
void CopyInt(int *source, int **destination);

int main(){
    int source[] = {1, 2, 3};
    int *destination;
    unsigned size = 3;
    CoppyArray(source, &destination, size);

    int i;
    for (i = 0; i < size; i++){
        printf("%d\t", *(destination + i));
    }
    printf("\n");
    free(destination);

    int int_source = 12;
    int *int_destination;
    CopyInt(&int_source, &int_destination);
    printf("int_destination: %d\n", *int_destination);

    return 0;
}

void CoppyArray(int *source, int **destination, unsigned size){
    *destination = malloc(sizeof(int) * size);
    *destination = source;
}

void CopyInt(int *source, int **destination){
    *destination = source;
}