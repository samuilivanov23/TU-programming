#include <stdio.h>
#include <string.h>

void CopyString(char *str1, char *str2);
int SumFirstLast(int number);
void PrimeNumberOperations(int number1, int number2);
void CheckSumOfPrimes(int number);
int CheckPrime(int number);
int IsPalindrome(char *str);

int main(){
    //TASK 1
    char str1[] = "Test 123";
    char str2[] = "ADADADADsadasd";
    CopyString(str1, str2);
    printf("String 2: %s\n", str2);

    //TASK 2
    int number = 7;
    int sum_first_last = SumFirstLast(number);
    printf("result: %d\n", sum_first_last);

    //TASK 3
    PrimeNumberOperations(1, 20);
    CheckSumOfPrimes(63);

    //TASK 4
    char string[20]; //static max length
    scanf("%s", string);
    int result_polindrome = IsPalindrome(string);
    if(result_polindrome){
        printf("%s is palindrome\n", string);
    }
    else{
        printf("%s is not palindrome\n", string);
    }
    
    return 0;
}

void CopyString(char *str1, char *str2){
    int i;

    for (i = 0; str1[i] != '\0'; i++) {
        str2[i] = str1[i];
    }

    str2[i] = '\0';
}

int SumFirstLast(int number){
    int lastDigit = number % 10;

    while(number >= 10)
    {
        number = number / 10;
    }

    return number + lastDigit; //number is the has the value of the last digit
}

void PrimeNumberOperations(int number1, int number2){
    int i = number1;

    while(i <= number2){
        int is_prime = CheckPrime(i);
        if(is_prime){
            printf("%d is prime\n", i);
        }
        i++;
    }
}

void CheckSumOfPrimes(int number){
    int i, flag = 0;
    for (i = 2; i <= number / 2; ++i) {
        if (CheckPrime(i) && CheckPrime(number - i)) {
            printf("%d: %d + %d\n", number, i, (number - i));
            flag = 1;
        }
    }

    if(!flag){
        printf("%d: can't be presented by sum of two primes", number);
    }
}


int CheckPrime(int number){
    int i = 2;
    for(i; i < number; i++){
        if(number % i == 0){
            return 0;
        }
    }

    return 1;
}

int IsPalindrome(char *str){
    int i = 0; //first char
    int j = strlen(str) - 1; //last char

    while(i < j){
        if(str[i] != str[j]){
            return 0;
        }

        i++;
        j--;
    }

    return 1;
}