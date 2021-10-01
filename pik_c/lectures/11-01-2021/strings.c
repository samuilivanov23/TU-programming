#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <memory.h>

char *ReadText();
char **Split(char *string, char delimiter, unsigned *size, unsigned *allocated_size);
unsigned CountDelimiters(char *string, char delimiter);
unsigned TokenLength(char *string, char delimiter);
void FreeStrings(char **strings, unsigned length);
void OutputStrings(char **strings, unsigned length);

int main(){
    char *text;
    char **result;
    unsigned array_size, allocated_size;

    text = ReadText();
    if(text == NULL){
        return EXIT_FAILURE;
    }

    result = Split(text, ',', &array_size, &allocated_size);

    if(result != NULL){
        OutputStrings(result, array_size);
        FreeStrings(result, allocated_size);
        result = NULL;
    }
    
    free(text);
    free(result);
    text = NULL;
    result = NULL;

    return 0;
}

char *ReadText(){
    char buffer[1024];
    char *string;

    printf("Enter string#> ");
    fgets(buffer, 1024, stdin);
    if(buffer[strlen(buffer) - 1] == '\n'){
        buffer[strlen(buffer) - 1] = '\0';
    }

    string = (char*)malloc(strlen(buffer) * sizeof(char));
    if(string == NULL){
        printf("Error while allocating memory");
        return NULL;
    }
    
    strcpy(string, buffer);
    return string;
}

char **Split(char *string, char delimiter, unsigned *array_size, unsigned *allocated_size){
    char **strings;
    char *tempString = string;
    int i;
    unsigned length;
    *allocated_size = CountDelimiters(string, delimiter) * sizeof(char*);
    *array_size = CountDelimiters(string, delimiter);

    strings = (char**)malloc((*allocated_size) * sizeof(char*));
    if(strings == NULL){
        printf("Error while allocating memory");
        return NULL;
    }

    for(i = 0; i < (*allocated_size); i++){
        length = TokenLength(tempString, delimiter);
        if((strings[i] = (char*)malloc(length * sizeof(char))) == NULL){
            printf("Error while allocating memory");
            FreeStrings(strings, i);
            return NULL;
        }

        memcpy(strings[i], tempString, length-1);
        strings[i][length] = '\0';
        tempString += length;
    }
    return strings;
}

unsigned CountDelimiters(char *string, char delimiter){
    char *temp = string-1;
    unsigned count = 1;

    if(strlen(string) == 0){
        return 0;
    }

    while(1){
        temp = strchr(temp+1, delimiter);
        if(temp == NULL){
            break;
        }
        count++;
    }
    return count;
}

unsigned TokenLength(char *string, char delimiter){
    unsigned length;
    char *end;

    end = strchr(string, delimiter);
    if(end == NULL){
        return strlen(string) + 1;
    }
    else{
        return end - string + 1;
    }
}

void FreeStrings(char **strings, unsigned length){
    int i;
    for(i = 0; i < length; i++){
        free(strings[i]);
        strings[i] = NULL;
    }

    free(strings);
}

void OutputStrings(char **strings, unsigned length){
    int i;

    for(i = 0; i < length; i++){
        puts(strings[i]);
    }
}