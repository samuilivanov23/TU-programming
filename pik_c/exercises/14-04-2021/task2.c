#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Product {
    int quantity;
    double price;
    char name[30];
    char manufacturer[30];
};

void InputProducts(struct Product *products, int length);
void SortProducts(struct Product *products, int length);
double AvgPrice(struct Product *products, int length);

int main()
{
    int size;
    printf("enter products array size: ");
    scanf("%d", &size);

    struct Product *products = (struct Product*)malloc(sizeof(struct Product) * size);

    InputProducts(products, size);
    SortProducts(products, size);
    double avg_price = AvgPrice(products, size);
    
    return 0;
}

void InputProducts(struct Product *products, int length)
{
    for(int i = 0; i < length; i++)
    {
        printf("enter name: ");
        scanf("%s", products[i].name);

        printf("enter manufacturer: ");
        scanf("%s", products[i].manufacturer);

        printf("enter quantity: ");
        scanf("%d", &products[i].quantity);

        printf("enter price: ");
        scanf("%lf", &products[i].price);
    }
}

void SortProducts(struct Product *products, int length)
{
    int i, j;
    struct Product temp;
    
    for (i = 0; i < length - 1; i++)
    {
        for (j = 0; j < (length - 1-i); j++)
        {
            if (strcmp(products[j].name, products[j + 1].name) > 0)
            {
                temp = products[j];
                products[j] = products[j + 1];
                products[j + 1] = temp;
            } 
        }
    }
}

double AvgPrice(struct Product *products, int length)
{
    double avg_price;
    for(int i = 0; i < length; i++)
    {
        avg_price += products[i].price;
    }

    avg_price = (double)avg_price/length;
    printf("average price: %lf\n", avg_price);

    return avg_price;
}
