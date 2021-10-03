#include <stdio.h>

void ModifyArray(int array[], unsigned length);
void ModifyArray2(int array[], unsigned length, int k);
int IsPolindrome(int n);

int main(){
    int array[] = {1, 2, 3, 4, 5, 6};
    unsigned length = 6;
    
    ModifyArray(array, length);
    printf("%d\n", array[1]);

    ModifyArray2(array, length, 3);
    printf("%d\n", array[3]);

    int is_polindrome = IsPolindrome(101);
    return 0;
}

void ModifyArray(int array[], unsigned length){
    int i;
    for(i = 0; i < length; i++){
        if(array[i] % 2 == 0){
            array[i] *= 10;
        }
    }

    return 1;    
}

void ModifyArray2(int array[], unsigned length, int k){
    int i;
    for(i = 0; i < length; i++){
        if(array[i] > k){
            array[i] = 0;
        }
    }

    return 1;
}

int IsPolindrome(int n){
    int reversed = 0, remainder, starting_number;
    starting_number = n;

    while (n != 0) {
        remainder = n % 10;
        reversed = reversed * 10 + remainder;
        n /= 10;
    }

    if (starting_number == reversed)
    {
        printf("%d is a palindrome.\n", starting_number);
        return 1;
    }
    else
    {
        printf("%d is not a palindrome.\n", starting_number);
        return 0;
    }
}