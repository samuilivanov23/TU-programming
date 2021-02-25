#include <stdio.h>

int FindDuplicate(int array[]);

int main(){
    int array[] = {3, 1, 3, 4, 2};
    unsigned int length = 6;
    int duplicate_number = FindDuplicate(array);
    printf("Duplicate number: %d\n", duplicate_number);
    return 0;
}

int FindDuplicate(int array[]){
    int tortoise = array[0];
    int hare = array[0];
    
    while(1){
        tortoise = array[tortoise];
        hare = array[array[hare]];
        printf("tortoise: %d\n", tortoise);
        printf("hare: %d\n", hare);
        if(tortoise == hare){
            break;
        }
    }

    int ptr1 = array[0];
    int ptr2 = tortoise;
    while(ptr1 != ptr2){
        ptr1 = array[ptr1];
        ptr2 = array[ptr2];
        printf("ptr1: %d\n", ptr1);
        printf("ptr2: %d\n", ptr2);
    }

    return ptr1;
}