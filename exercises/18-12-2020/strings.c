#include <stdio.h>

void strcpylast(char *strdest, char *strend);

int main(){
    char strdest[10] = "abcdef";
    char strend[10] = "34"; 
    
    strcpylast(strdest, strend);

    return 0;
}

void strcpylast(char *strdest, char *strend){
    int i, j;

    for(i = 0 ; *(strdest + i) != '\0'; i++); // find length of str1 (insted of strlen())

    j = 0;
    while(*(strend + j) != '\0'){
        *(strdest + i) = *(strend + j);
        j++;
        i++;
    }

    *(strdest + i) = '\0';
    printf("%s\n", strdest);
}