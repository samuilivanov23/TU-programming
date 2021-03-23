#include <stdio.h>
#include <stdlib.h>

void CreateBinaryFile(FILE *, int *array_length);
void ReadBinaryFile(FILE *, int array_length);
void SortArray(int array[], int array_length);
void PrintArray(int array[], int array_length);

int main(){
    FILE *file_stream;
    if((file_stream = fopen("array.txt", "wb")) == NULL){
        printf("Cannot open file for WRITE. \n");
        exit(EXIT_FAILURE);
    }

    int array_length = 0;
    CreateBinaryFile(file_stream, &array_length);
    fclose(file_stream);

    if((file_stream = fopen("array.txt", "rb")) == NULL){
        printf("Cannot open file for READ. \n");
        exit(EXIT_FAILURE);
    }

    ReadBinaryFile(file_stream, array_length);
    fclose(file_stream);
    return 0;
}

void CreateBinaryFile(FILE *file_stream, int *array_length){
    int number, count;
    while(scanf("%d", &number) != EOF){
        fwrite(&number, sizeof(int), 1, file_stream);
        (*array_length)++;
    }
    printf("Write end\n");
}

void ReadBinaryFile(FILE *file_stream, int array_length){
    int array[array_length], i, even, odd, tmp_num;
    while(!feof(file_stream)){
        if(fread(&array[i], sizeof(int), 1,  file_stream) != 1){
            printf("Read error occured. \n");
            //exit(EXIT_FAILURE);
        }

        printf("[%d] = %d\n", i, array[i]);
        if(array[i] % 2 == 0){
            even++;
        }
        else{
            odd++;
        }

        i++;
    }
    SortArray(array, array_length);
    PrintArray(array, array_length);
}

void SortArray(int array[], int array_length){
    int i, key, j;

    for (i = 1; i < array_length; i++) {
        key = array[i];
        j = i - 1;
 
        while (j >= 0 && array[j] > key) {
            array[j + 1] = array[j];
            j = j - 1;
        }
        array[j + 1] = key;
    }
}

void PrintArray(int array[], int array_length){
    int i;
    for(i = 0; i < array_length; i++){
        printf("[%d] %d\n", i, array[i]);
    }
    printf("Read end\n");
}