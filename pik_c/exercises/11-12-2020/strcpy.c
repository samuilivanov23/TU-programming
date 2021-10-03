#include <stdio.h>

void myStrcpy(char *str1, char *str2);

int main(){
    char str1[5];
    char str2[5] = {'1', '2', '3', '\0', '4'};

    char str1[50] = "abcdef"; 
    char str2[50] = "1234"; 
    int i, j;

    for(i=0; str1[i]!='\0'; ++i); // find length of str1 (insted of strlen())
    
    for(j=0; str2[j]!='\0'; ++j, ++i)
    {
        str1[i]=str2[j];
    }

    str1[i]='\0'; // end of string
    printf("\nOutput: %s",str1);
    
    myStrcpy(str1, str2);

    printf("%s\n", str1);
    printf("%s\n", str2);
    
    return 0;
}

void myStrcpy(char *str1, char *str2){
    int i = 0;

    while(*(str2) != '0'){
        
    }
}