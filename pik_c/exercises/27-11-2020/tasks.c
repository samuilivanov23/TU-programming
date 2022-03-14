#include <stdio.h>

int MinDivisibleBy5(int arr[], int length);
double Average(int arr[], int length);
int Min(int a, int b);
void SwapArray(int * arr, int length);

int main()
{
    int length = 5;
    int arr[5];

    int i = 0;
    for (; i < length; i++){
        scanf("%d", &arr[i]);
    }

    int min = MinDivisibleBy5(arr, length);
    printf("min %d\n", min);

    double average = Average(arr, length);
    printf("%lf\n", average);
    
    int temp_arr[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    SwapArray(temp_arr, 9);

    i = 0;
    for(; i < 9; i++){
        printf("%d ", temp_arr[i]);
    }

    return 0;
}

int MinDivisibleBy5(int arr[], int length)
{
    int min_el = __INT_MAX__;

    int i = 0;
    for (; i < length; i++) { 
        if (arr[i] % 5 == 0) 
            min_el = Min(min_el, arr[i]);
    }

    return min_el;
}

double Average(int arr[], int length){
    double average = 0;
    int sum = 0;

    int i = 0;
    for (; i < length; i++){
        sum += arr[i];    
    }

    average = (double)sum/length;

    return average;
}

void SwapArray(int * arr, int length){
    int i = 0;
    int middle = (length/2) + 1;
    int j = middle;

    for(; i < middle; i++){
        int temp = *(arr + i);
        *(arr + i) = *(arr + j);
        *(arr + j) = temp;
    
        j++;
    }
}

int Min(int a, int b){
    if (a < b){
        return a;
    }
    else{
        return b;
    }
    
}