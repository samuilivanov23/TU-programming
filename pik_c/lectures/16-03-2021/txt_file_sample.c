#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum TBoolean {FALSE, TRUE};

void ReadString(char *file_name, char *template_string);
enum TBoolean SearchFor(char *string, char *pattern);

int main(int argc, char **argv){
    // printf("file is: %s\n", argv[1]);
    // char *file_name = argv[1];

    const unsigned SIZE = 256;
    char file_name[SIZE];
    char template_strng[SIZE];

    if(fgets(file_name, SIZE, stdin) == NULL){
        perror(NULL);
        return EXIT_FAILURE;
    }
    if(strlen(file_name) < SIZE - 1){
        file_name[strlen(file_name) - 1] = '\0';
    }

    if(fgets(template_strng, SIZE, stdin) == NULL){
        perror(NULL);
        return EXIT_FAILURE;
    }
    if(strlen(template_strng) < SIZE - 1){
        template_strng[strlen(template_strng) - 1] = '\0';
    }

    ReadString(file_name, template_strng);
    return 0;
}

void ReadString(char *file_name, char *template_string){
    FILE *file_input;
    const unsigned SIZE = 1001; //max size of line in the file
    char buffer[SIZE];

    if((file_input = fopen(file_name, "r")) == NULL){
        perror("fopen");
        exit(EXIT_FAILURE);
    }

    while(!(feof(file_input))){
        if(fgets(buffer, SIZE, file_input) == NULL){
            perror("fgets");
            fclose(file_input);
            exit(EXIT_FAILURE);
        }
        
        if(SearchFor(buffer, template_string)){
            puts(buffer);
        }
    }

    fclose(file_input);
}

enum TBoolean SearchFor(char *string, char *pattern){
    return strstr(string, pattern) != NULL;
}