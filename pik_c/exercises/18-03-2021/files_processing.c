#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void Write5Strings(FILE *);
void Read5Strings(FILE *);
void CreateBinaryFile(FILE *);
void SearchNumber(FILE *);
int NmberOfWords(FILE *);
int NmberOfSentences(FILE *);
void Writing();
void Reading();
void FirstExercise();
void SecondExercise();
void ThirdExercise();
void FourthExercise();

int main(){
    //FirstExercise();
    //SecondExercise();
    //ThirdExercise();
    FourthExercise();
    return 0;
}

//FIRST----------------------------------------------------------------------------------------------------------------
void FirstExercise(){
    FILE *file_stream;
    if((file_stream = fopen("strings.txt", "w")) == NULL){
        printf("Cannot open file for WRITE. \n");
        exit(EXIT_FAILURE);
    }
    Write5Strings(file_stream);
    fclose(file_stream);

    printf("------------------\n");

    if((file_stream = fopen("strings.txt", "r")) == NULL){
        printf("Cannot open file for READ. \n");
        exit(EXIT_FAILURE);
    }
    Read5Strings(file_stream);
    fclose(file_stream);
}

void Write5Strings(FILE *file_stream){
    int i;
    char buffer[30];
    for (i = 0; i < 5; i++){
        fgets(buffer, sizeof(buffer), stdin);
        if(fputs(buffer, file_stream) == EOF){
            printf("ERROR\n");
            perror(NULL);
        }
    }
}

void Read5Strings(FILE *file_stream){
    char buffer[30];
    while (fgets(buffer, sizeof(buffer), file_stream)) {
        printf("%s", buffer);
    }
}


//SECOND----------------------------------------------------------------------------------------------------------------
void SecondExercise(){
    FILE *file_stream;
    if((file_stream = fopen("numbers.bin", "wb")) == NULL){
        printf("Cannot open file for WRITE. \n");
        exit(EXIT_FAILURE);
    }

    int array_length = 0;
    CreateBinaryFile(file_stream);
    fclose(file_stream);

    if((file_stream = fopen("numbers.bin", "rb")) == NULL){
        printf("Cannot open file for READ. \n");
        exit(EXIT_FAILURE);
    }

    SearchNumber(file_stream);
    fclose(file_stream);
}

void CreateBinaryFile(FILE *file_stream){
    int number, i;
    srand(0);

    i = 0;
    while(i < 50){
        number = rand();
        fwrite(&number, sizeof(int), 1, file_stream);
        printf("%d\n", number);
        i++;
    }
    printf("Write end\n");
}

void SearchNumber(FILE *file_stream){
    int number_to_search, result_number;
    while(1){
        printf("Enter num to search: ");
        scanf("%d", &number_to_search);
        if(number_to_search >=0 && number_to_search < 50){
            break;
        }
    }

    fseek(file_stream, sizeof(int)*number_to_search - 1, SEEK_SET);
    if(fread(&result_number, sizeof(int), 1,  file_stream) != 1){
            printf("Read error occured. \n");
            //exit(EXIT_FAILURE);
    }

    printf("Result: %d\n", result_number);
}


//THIRD----------------------------------------------------------------------------------------------------------------
void ThirdExercise(){
    FILE *file_stream;
    if((file_stream = fopen("sample.txt", "r")) == NULL){
        printf("Cannot open file for READ. \n");
        exit(EXIT_FAILURE);
    }
    int num_words = NmberOfWords(file_stream);
    int num_sentences = NmberOfSentences(file_stream);

    printf("words: %d\n", num_words);
    printf("sentences: %d\n", num_sentences);

    fclose(file_stream);
}

int NmberOfWords(FILE *file_stream){
    int word_count = 1;
    fseek(file_stream, 0, SEEK_SET);

    int i;
    while(1){
        i = fgetc(file_stream);
        if(i == EOF){
            break;
        }

        if(i == ' ' || i == '\n' || i == '\0'){
            word_count++;
        }
    }

    return word_count;
}

int NmberOfSentences(FILE *file_stream){
    int sentences_count = 1;
    fseek(file_stream, 0, SEEK_SET);

    int i;
    while(1){
        i = fgetc(file_stream);
        if(i == EOF){
            break;
        }

        if(i == '.' || i == '?' || i == '\0' || i == '!'){
            sentences_count++;
        }
    }

    return sentences_count - 1;
}


//FOURTH----------------------------------------------------------------------------------------------------------------
void FourthExercise(){
    Writing();
    Reading();
}

void Writing(){
    fflush(stdin);
    int i, number, j;
    double price;
    char article[50];
    printf("enter string less than 50\n");
    fgets(article, sizeof(article), stdin);
    j = ((sizeof(article)));
    printf("enter the number: ");
    scanf("%d", &number);
    printf("enter price: ");
    scanf("%lf", &price);

    FILE *file_stream;
    if((file_stream = fopen("stocks.bin", "ab")) == NULL){
        printf("Cannot open file for WRITE. \n");
        exit(EXIT_FAILURE);
    }

    if(fwrite(&number, sizeof(int), 1, file_stream) != 1){
        printf("writing error\n");
    }
    if(fwrite(&j, sizeof(int), 1, file_stream) != 1){
        printf("writing error\n");
    }
    if(fwrite(article, sizeof(article), 1, file_stream) != 1){
        printf("writing error\n");
    }
    if(fwrite(&price, sizeof(double), 1, file_stream) != 1){
        printf("writing error\n");
    }

    fclose(file_stream);
}

void Reading(){
    int i, number, number1;
    char article[50];
    double price;
    FILE *file_stream;
    printf("enter the number: ");
    scanf("%d", &number1);
    if((file_stream = fopen("stocks.bin", "rb")) == NULL){
        printf("Cannot open file for WRITE. \n");
        exit(EXIT_FAILURE);
    }

    for(;;){
        if(fread(&number, sizeof(int), 1, file_stream) != 1){
            printf("reading error\n");
            break;
        }
        if(fread(&i, sizeof(int), 1, file_stream) != 1){
            printf("reading error\n");
            exit(1);
        }
        if(fread(article, 1, i, file_stream) != 1){
            printf("reading error\n");
            exit(7);
        }
        if(fread(&price, sizeof(double), 1, file_stream) != 1){
            printf("reading error\n");
            exit(5);
        }

        if(number == number1){
            printf("%d\n", number);
            printf("%s\n", article);
            printf("%f\n", price);
            break;
        }
    }

    fclose(file_stream);
}