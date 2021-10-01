#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Item_Struct Item;
struct Item_Struct
{
    char name[30];
    int weight;
    char type[3];
    double price;
};

typedef struct Node_Struct Node;
struct Node_Struct
{
    Item item;
    Node *next;
};

void FreeList( Node *head );
Node *IsIn( Node *head, int id );
void ExpiresOn( Node *head, char date[] );
Node *AddItemToShop( Node *head, Node *new );
Node *CreateList( Node *head, FILE *file_stream );

int main()
{
    Node *head = NULL;
 
    FILE *file_stream;
    if( ( file_stream = fopen( "items", "r+b" ) ) == NULL )
    {
        printf( "Cannot open file. \n" );
    }
    else
    {
        CreateList( head, file_stream );
    }
 
    fclose( file_stream );
    FreeList( head );
 
    return 0;
}

Node *CreateList( Node *head, FILE *file_stream ){
    Item item;
  
    while( 1 )
    {
        if( fread( &item, sizeof(item), 1, file_stream ) != 1 )
        {
            printf("An error occured while reading from file.\n");
            exit(1);
        }

        if( feof( file_stream ) != 0 )
        {
            break;
        }
        
        Node *current = ( Node* )malloc( sizeof( Node ) );
        current->item = item;
        head = AddItemToShop( head, current );
    }

    return head;
}

Node *AddItemToShop( Node *head, Node *new )
{
  if( head != NULL )
  {  
    new->next = head;
  }

  head = new;
  return head;
}

void ExpiresOn( Node *head, char date[] )
{
    Node *current = head;
 
    while( current != NULL )
    {
        if( strcmp( date, current->item.expire_date ) > 0 )
        {
            printf( "Name: %s, Price: .2%lf\n", current->item.name, current->item.price );
        }
 
        current = current->next;
    }
}

Node *IsIn( Node *head, int id ){
    Node *result = NULL;
 
    Node* current = head;
    while( current != NULL )
    {
        if( current->item.id == id )
        {
            result = current;
            break;
        }
        current = current->next;
    }
 
    return result;
}

void FreeList( Node *head )
{
    Node *current = head;
    while( head != NULL )
    {
        head = head -> next;
        free( current );
        current = head;
    }
}