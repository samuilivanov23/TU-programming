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
double TotalCost( Node *head, char ch[] );
Node *AddItemToShop( Node *head, Node *new );
void Reverse( FILE *file_stream, Node *head );
Node *CreateList( Node *head, FILE *file_stream );
void WriteToFile( FILE *file_stream, Node *head, int numbers[], int count );

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

double TotalCost( Node *head, char ch[] )
{
    Node *current = head;
    double total_cost = 0;

    while( current != NULL )
    {
        if( strcmp( ch, current->item.type ) == 0 )
        {
            total_cost += ( current->item.price * current->item.weight );
        }
 
        current = current->next;
    }

    return total_cost;
}

Node *CreateList( Node *head, FILE *file_stream )
{
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

void WriteToFile( FILE *file_stream, Node *head, int numbers[], int count )
{
    Node *current = head;
    int current_index = 1;

    while( current )
    {
        for ( int i = 0; i < count; i++ )
        {
            if ( current_index == numbers[i] )
            {
                if( fwrite( &current->smartphone, sizeof(current->smartphone), 1, file_stream ) != 1 )
                {
                    printf("An error occured while writing to file.\n");
                    exit(1);
                }
                break;
            }
        }

        current_index++;
        current = current->next;
    }

    printf( "Successfully saved data to %s\n", file_path );
}

void Reverse( FILE *file_stream, Node *head )
{
    Node *new_head = NULL;
    Node *current = head;

    while( current )
    {   
        new_head = AddItemToShop( new_head, current );

        current = current->next;
    }

    Node *current = new_head;

    while( current )
    {
        if( fwrite( &current->smartphone, sizeof(current->smartphone), 1, file_stream ) != 1 )
        {
            printf("An error occured while writing to file.\n");
            exit(1);
        }
        current_index++;
        current = current->next;
    }

    printf( "Successfully saved data to %s\n", file_path );
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