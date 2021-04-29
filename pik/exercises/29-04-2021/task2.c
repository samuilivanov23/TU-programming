#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Picture 
{
    char code[20];
    char artist_name[20];
    char name[20];
    double price;
};

struct Node 
{
    struct Picture picture;
    struct Node *next;
};

typedef struct Node Node;

Node *NewItem();
Node *CreateNodeList();
Node *InsertNewElement(Node *head, Node *new);
Node *Delete(struct Node *head);
void PrintHighestPrice(struct Node *head);
void PrintList(Node* head);
void FreeNode(Node *head);

int main(){
    Node *head = NULL;
    
    int command = -1;
    while(command != 0)
    {
        printf("MENU\n");
        printf("0. EXIT\n");
        printf("1. CREATE List\n");
        printf("2. ADD new data\n");
        printf("3. Delete picture\n");
        printf("4. SEARCH by price\n");
        printf("5. PRINT info for all pictures\n");
        printf("###############\n");

        printf("Your command: ");
        scanf("%d", &command);

        switch(command)
        {
            case 1:
                head = CreateNodeList();
                break;
            case 2:
                head = InsertNewElement(head, NewItem());
                break;
            case 3:
                head = Delete(head);
                break;
            case 4:
                PrintHighestPrice(head);
                break;
            case 5:
                PrintList(head);
                break;
        }
    }

    FreeNode(head);

    return 0;
}

Node *NewItem()
{
    Node *result = NULL;
    result = (Node*)malloc(sizeof(Node));
    struct Picture picture;

    printf("Enter unique code: ");
    scanf("%s", picture.code);
    printf("Enter name of artist_name: ");
    scanf("%s", picture.artist_name);
    printf("Enter name of picture: ");
    scanf("%s", picture.name);
    printf("Enter price of picture: ");
    scanf("%lf", &picture.price);
    
    result->picture = picture;
    result->next = NULL;

    return result;
}

Node *CreateNodeList()
{
    int n;
    printf("Enter n: ");
    scanf("%d", &n);

    Node *head = NULL;
    Node *last = NULL;

    for(int i = 0; i < n; i++)
    {
        if(head == NULL)
        {
            head = NewItem();
            last = head;
        }
        else
        {
            last->next = NewItem();
            last = last->next;
        }
    }

    return head;
}

Node *InsertNewElement(Node *head, Node *new)
{
    new->next = head;
    head = new;
    return head;
}

Node *Delete(struct Node *head)
{
    char name[20];
    printf("Enter name to deleted: ");
    scanf("%s", name);

    while (head && (strcmp(name, head->picture.name) == 0))
    {   
        head = head->next;
        free(head);
    }

    struct Node* current;
    for(current = head; current != NULL; current = current->next)
    {
        while(current->next != NULL && (strcmp(name, current->next->picture.name) == 0))
        {
            struct Node* temp = current->next;
            current->next = temp->next;
            free(temp);
        }
    }

    free(current);
    return head;
}

void PrintHighestPrice(struct Node *head)
{
    Node* current = head;
    Node* highest = head;
    
    while(current != NULL)
    {
        if(current->picture.price > highest->picture.price)
        {
            highest = current;
        }
        current = current->next;
    }

    printf("Printing info for highest price: \n");
    printf("Unique code: %s\n, artist_name: %s\n, Name: %s\n, Price: %lf\n", 
                                                                        highest->picture.code, 
                                                                        highest->picture.artist_name, 
                                                                        highest->picture.name, 
                                                                        highest->picture.price);
}

void PrintList(Node* head)
{
    Node* current = head;
    while(current != NULL)
    {
        printf("Unique code: %s\n, artist_name: %s\n, Name: %s\n, Price: %lf\n", 
                                                                            current->picture.code, 
                                                                            current->picture.artist_name, 
                                                                            current->picture.name, 
                                                                            current->picture.price);
                                                                            current = current->next;
    }
}

void FreeNode(Node *head)
{
    Node *current = head;
    while(head != NULL)
    {
        head = head -> next;
        free(current);
        current = head;
    }
}