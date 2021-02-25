#include <stdio.h>

char* ReadWord();
int sum(int x, int y);
int sub(int x, int y);
int (*p[2])(int x, int y);

int main(){
    // printf("Result: %s\n", ReadWord());

    int result, i, j, oper;
    printf("Enter 2 numbers: ");
    scanf("%d %d", &i, &j);
    printf("0: ADD, 1: SUBTRACT: ");
    scanf("%d", &oper);
    result = (*p[oper])(i, j);
    printf("%d", result);
    return 0;
}

char* ReadWord(){
    static char word[20];
    printf("Enter word: ");
    scanf("%s", word);
    return word;
}