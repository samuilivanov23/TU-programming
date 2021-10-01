#include <stdio.h>
#include <stdlib.h>

typedef struct Car_Struct Car;
struct Car_Struct{
  char brand[30];
  char model[30];
  char color[30];
  double price;
};

// The structure for a single Node
typedef struct Node_Struct Node;
struct Node_Struct{
  Car car;
  Node *next;
};

void PrintList(Node *head);
Node *InsertData();
Node *NewItem();
Node *Delete(Node *head, double price);
void FreeList(Node *head);

int main(){
    Node *head = InsertData();
    PrintList(head);
    Delete(head, 10.50);
    PrintList(head);
    FreeList(head);
    return 0;
}

Node *InsertData()
{
    int num_nodes;
    printf("Enter number of nodes: ");
    scanf("%d", &num_nodes);

    Node *root = NULL;
    Node *last = NULL;

    int i = 0;
    while(i < num_nodes){

        if(root == NULL)
        {
            root = NewItem();
            last = root;
        }
        else
        {
            last->next = NewItem();
            last = last->next;
        }
        i++;
    }

    return root;
}

Node *NewItem()
{
    Node *result = NULL;
    result = (Node *)malloc(sizeof(Node));

    Car car;
    char brand[30];
    printf("Input brand for node: ");
    scanf("%s", result->car.brand);

    char model[30];
    printf("Input model for node: ");
    scanf("%s", result->car.model);

    char color[30];
    printf("Input color for node: ");
    scanf("%s", result->car.color);

    double price;
    printf("Input price for node: ");
    scanf("%lf", &result->car.price);

    result->next = NULL;
    return result;
}

void PrintList(Node *head)
{
  while(head != NULL)
  {
    printf("brand: %s\nmodel: %s\ncolor: %s\nprice: %lf\n", head->car.brand, head->car.model, head->car.color, head->car.price);
    head = head->next;
  }
}

Node *Delete(Node *head, double price)
{
    while(head && head->car.price < price)
    {
        head = head->next;
        free(head);
    }

    Node *current;
    for(current = head; current != NULL; current = current->next)
    {
        while (current->next != NULL && current->next->car.price < price)
        {
            Node *tmp = current->next;
            current->next = tmp->next;
            free(tmp);
        }
    }

    free(current);
    return head;
}

void FreeList(Node *head)
{
    Node *current = head;

    while(head != NULL)
    {
        head = head->next;
        free(current);
        current = head;
    }
}