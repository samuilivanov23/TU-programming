#ifndef ARRAYS_H_INCLUDED
#define ARRAYS_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 3
#define COLS 4

void freeArray(double **data, int rows){
    int i;

    for(i = 0; i < rows; i++){
        free(data[i]);
        data[i] = NULL;
    }
    free(data);
    data = NULL;
}

double** createArray(unsigned rows, unsigned cols){
    double **array;
    char text[80];
    int i;

    array = (double**)malloc(rows * sizeof(double*));
    if(array == NULL){
        perror("row:7 in dynamic_arrays.c");
        exit(EXIT_FAILURE);
    }

    for(i = 0; i < rows; i++){
        array[i] = (double*)calloc(cols, sizeof(double));
        if(array[i] == NULL){
            sprintf(text, "row:15 in dynamic_arrays.c for %d iteration", i);
            perror(text);
            freeArray(array, i);
            return NULL;
        }
    }

    return array;
}

void initArray(double **data, unsigned rows, unsigned cols){
    int i, j;

    srand((unsigned)time(NULL)); //different pseudo-random numbers

    for(i = 0; i < rows; i++){
        for(j = 0; j < cols; j++){
            data[i][j] = rand() % 21; //from 0 to 20
        }
    }
}

void inputArray(double **data, unsigned rows, unsigned cols){
    int i, j;

    for(i = 0; i < rows; i++){
        for(j = 0; j < cols; j++){
            printf("A(%d,%d) = ", i + 1, j + 1);
            scanf("%lf", &data[i][j]);
        }
    }
}

void printArray(double **data, unsigned rows, unsigned cols){
    int i, j;

    for(i = 0; i < rows; i++){
        for (j = 0; j < cols; j++){
            printf("%g\t", data[i][j]);
        }
        printf("\n");
    }
}

#endif // ARRAYS_H_INCLUDED