#include <stdio.h>
#include <string.h>

struct Book {
    int year;
    double price;
    char title[30];
    char author[30];
};

void InputBooks(struct Book *books);
void PrintAfter2005(struct Book *books);
void SearchAuthor(struct Book *books);

int main()
{
    struct Book books[5];
    InputBooks(books);
    PrintAfter2005(books);
    SearchAuthor(books);
    return 0;
}

void InputBooks(struct Book *books)
{
    for(int i = 0; i < 5; i++)
    {
        printf("enter title: ");
        scanf("%s", books[i].title);

        printf("enter author: ");
        scanf("%s", books[i].author);

        printf("enter year: ");
        scanf("%d", &books[i].year);

        printf("enter price: ");
        scanf("%lf", &books[i].price);
    }
}

void PrintAfter2005(struct Book *books)
{
    for(int i = 0; i < 5; i++)
    {
        if(books[i].year > 2005)
        {
            printf("title: %s\n", books[i].title);
            printf("author: %s\n", books[i].author);
            printf("year: %d\n", books[i].year);
            printf("price: %lf\n", books[i].price);
            printf("----------------------------------\n");
        }
    }
}

void SearchAuthor(struct Book *books)
{
    char author[30];

    printf("enter author: ");
    scanf("%s", author);
    
    for(int i = 0; i < 5; i++)
    {
        if(strcmp(author, books[i].author) == 0)
        {
            printf("title: %s\n", books[i].title);
            printf("author: %s\n", books[i].author);
            printf("year: %d\n", books[i].year);
            printf("price: %lf\n", books[i].price);
            printf("----------------------------------\n");
        }
    }
}