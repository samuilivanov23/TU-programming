#include <stdio.h>
#include <stdlib.h>

void example1();
void example2();

int main(){
    example1();
    example2();

    return 0;
}

void example1(){
    char str[80] = "This is a file system test. \n";
    FILE *fp;
    char *p;
    int i;

    if((fp = fopen("myfile", "w")) == NULL){
        printf("Cannot open file. \n");
        exit(1);
    }

    if(fputs("Testing fputs finction\n", fp) == EOF){
        printf("ERROR\n");
        perror(NULL);
    }

    p = str;
    while(*p){
        if(fputc(*p, fp) == EOF){
            printf("Error writting to file. \n");
            exit(1);
        }
        p++;
    }

    fclose(fp);

    if((fp = fopen("myfile", "r")) == NULL){
        printf("Cannot open file. \n");
        exit(1);
    }

    for(;;){
        i = fgetc(fp);
        if(i == EOF){
            break;
        }
        putchar(i);
    }

    fclose(fp);
}

void example2(){
    FILE *fp;
    double id;
    int d;
    char str[80];

    if((fp = fopen("file1", "w")) == NULL){
        printf("Cannot open file. \n");
        exit(1);
    }

    fprintf(fp, "%f %d %s", 12345.342, 1908, "hello");

    fclose(fp);

    if((fp = fopen("file1", "r")) == NULL){
        printf("Cannot open file. \n");
        exit(1);
    }

    fscanf(fp, "%lf%d%s", &id, &d, str);
    printf("%f %d %s", id, d, str);
    fclose(fp);
}