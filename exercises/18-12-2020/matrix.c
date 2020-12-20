#include <stdio.h>

int matrix_manipulation(int arr[5][5], unsigned size);

int main(){
    // testing lengths
    int matrix[5][5] = {
        {1, 2, 3, 4, 5},
        {4, 5, 6, 7, 8},
        {9, 10, 11, 12, 13},
        {14, 15, 16, 17, 18},
        {19, 20, 21, 22, 23}
    };

    int multiplication = matrix_manipulation(matrix, 5);
    printf("result: %d\n", multiplication);
    return 0;
}

int matrix_manipulation(int arr[5][5], unsigned size){
    int i = 0;
    int sum = 0;

    for(; i < size; i++){
        sum += arr[i][i];
    }

    int multiplication = 1;
    i = 0;
    int j = 0;
    for(; i < size; i++){
        for(j = i + 1; j < size; j++){
            if(arr[i][j] % 3 == 0 && arr[i][j] > sum){
                multiplication *= arr[i][j];
            }
        }
    }

    return multiplication;
}