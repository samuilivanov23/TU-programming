#include <stdio.h>
#include <math.h>

#define FALSE 0
#define TRUE 1

//12 -> 3, 123 -> 6
int sumDigits(int);
void printSumOfDigits();
int isEven(int);
void printEvenSumOfDigits();
int lastDigit(int);
int firstDigit(int);
void countNumbersWithEqualFirstAndLastDigits();

int main(){
    // printSumOfDigits();
    // printEvenSumOfDigits();
    countNumbersWithEqualFirstAndLastDigits();
    return 0;
}

int sumDigits(int number){
    int sum = 0;
    number = number < 0 ? number *= -1 : number; //*beautiful <3

    while (number != 0){
        sum    += number % 10;
        number /= 10;
    }

    return sum;
}

void printSumOfDigits(){
    int number;
    do{
        printf("Enter number: ");
        scanf("%d", &number);

        if (number != 0){
            printf("Sum of digits: %d\n", sumDigits(number));
        }
    } while(number != 0);
}

int isEven(int number){
    return number % 2 == 0;
}

void printEvenSumOfDigits(){
    int number = 1, sum = 0;

    while (TRUE){
        printf("Enter number: ");
        scanf("%d", &number);

        if (number == 0){ //! strahoten kod bravo babo :)))
            break;
        }

        if(isEven(sumDigits(number)) == TRUE){
            sum += number;
        }
    }

    printf("Sum: %d\n", sum);
}

int lastDigit(int number){
    return number % 10;
}

int firstDigit(int number){
    while(number > 10){
        number /= 10;
    }

    return number;
}

void countNumbersWithEqualFirstAndLastDigits(){
    int number = 1, count = 0;

    while (TRUE){
        printf("Enter number: ");
        scanf("%d", &number);

        if (number == 0){
            break;
        }

        int absoluteNumber = fabs(number);
        if(absoluteNumber > 10 && (firstDigit(absoluteNumber) == lastDigit(absoluteNumber))){
            count++;
        }
    }

    printf("Count: %d\n", count);
}
