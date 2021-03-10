#include <stdio.h>
#include <stdlib.h>

int *ReadFile(char *file_name, unsigned *length);

int main(){
    int *file_array;
    unsigned length;
    file_array = ReadFile("files/array_input.txt", &length);
    int i;
    for (i = 0; i < length; i++){
        printf("arr[%d] : %d\n", i, file_array[i]);
    }

    free(file_array);
    file_array = NULL;
    
    return 0;
}

int *ReadFile(char *file_name, unsigned *length){
    FILE *input_file;
    int *array = NULL;
    int temp;
    unsigned count = 0;
    *length = 0;

    input_file = fopen(file_name, "r");
    if(input_file == NULL){
        perror(NULL);
        return array;
    }

    while(1){
        if(fscanf(input_file, "%d", &temp) != 1){
            if(feof(input_file)){
                break;
            }
            perror(NULL);
            *length = count;
            return array;
        }

        array = (int*)realloc(array, ++count);
        printf("count: %d\n", count);
        printf("temp: %d\n", temp);

        if(array == NULL){
            printf("ERROR\n");
            perror(NULL);
            *length = count;
            return array;
        }
        
        printf("INSERT\n");
        array[count-1] = temp;
    }
    
    fclose(input_file);
    *length = count;
    return array;
}