#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

typedef int (*Operation)(int num1, int num2);
int Add(int num1, int num2);
int Multiply(int num1, int num2);

typedef struct{
    int number1;
    int number2;
    int result;
    Operation operation;
} MathCalculator;

int main(int argc, char **argv){
    int number1 = strtol(argv[1], NULL, 10);
    int number2 = strtol(argv[2], NULL, 10);  
    
    printf("number1: %d\n", number1);
    printf("number2: %d\n", number2);
   
    MathCalculator math_calculator;
    math_calculator.operation = Add;
    math_calculator.result = math_calculator.operation(5, 3);
    printf("%d\n", math_calculator.result);

    math_calculator.operation = Multiply;
    math_calculator.result = math_calculator.operation(5, 3);
    printf("%d\n", math_calculator.result);
    return 0;
}

int Add(int num1, int num2){
    return num1 + num2;
}

int Multiply(int num1, int num2){
    return num1*num2;
}
