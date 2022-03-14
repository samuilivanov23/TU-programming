#include <stdio.h>
#include <stdlib.h>
#include "./arrays.h"

int main(){
    double **data = NULL;
    
    data = createArray(ROWS, COLS);

    // inputArray(data, ROWS, COLS);
    initArray(data, ROWS, COLS);
    printArray(data, ROWS, COLS);

    freeArray(data, ROWS);
    data =  NULL; //is this necessary ??

    return EXIT_SUCCESS;
}