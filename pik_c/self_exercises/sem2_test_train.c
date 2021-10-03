#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING_SIZE 30

typedef struct Item_Struct Item;
struct Item_Struct 
{
    int id;
    char name[MAX_STRING_SIZE];
    char brand[MAX_STRING_SIZE];
    int kg;
    double price;
};

typedef struct Node_Struct Node;
struct Node_Struct
{
    Item item;
    Node *next;
};

Node *NewItem();
void PrintData();
Node *CreateList();
void PrintList( Node *head );
Node *AddItemToList( Node *head, Node *new );
void SaveDataToFile( Node *head, FILE *file_stream );
void ReadDataFromFile(FILE *file_stream);

int main()
{
    Node *head = NULL;
    head = AddItemToList( head, NewItem() );
    PrintList( head );
    char file_path[30] = "/tmp/sem2_test.bin";
    FILE *file_stream;

    if( ( file_stream = fopen( file_path, "wb" ) ) == NULL )
    {
        printf( "An error occured while trying to open the file %s\n", file_path );
        perror( "Error: " );
        exit(1);
    }

    SaveDataToFile( head, file_stream );
    fclose( file_stream );

    if( ( file_stream = fopen( file_path, "rb" ) ) == NULL )
    {
        printf( "An error occured while trying to open the file %s\n", file_path );
        perror( "Error: " );
        exit(1);
    }

    ReadDataFromFile( file_stream );
    fclose( file_stream );
 
    return 0;
}

Node *NewItem()
{
    Item new_item;
    printf( "Enter id:" );
    scanf( "%d", &new_item.id );
    getchar();
    
    printf( "Enter name: " );
    fgets( new_item.name, MAX_STRING_SIZE, stdin );
    new_item.name[strlen( new_item.name ) - 1] = '\0';
    
    printf( "Enter brand: " );
    fgets( new_item.brand, MAX_STRING_SIZE, stdin );
    new_item.brand[strlen( new_item.brand ) - 1] = '\0';
    
    printf( "Enter kg:" );
    scanf( "%d", &new_item.kg );
 
    printf( "Enter price:" );
    scanf( "%lf", &new_item.price );
 
    Node *new_item_node = ( Node* )malloc( sizeof( Node ) );
    new_item_node->item = new_item;
    
    return new_item_node; 
}

Node *AddItemToList( Node *head, Node *new )
{
    if( head != NULL )
    {
        new->next = head;
    }

    head = new;
    return head;
}

void PrintList( Node *head )
{
    Node *current = head;
    while(current)
    {
        PrintData( current->item );
        current = current->next;
    }
}


void SaveDataToFile( Node *head, FILE *file_stream )
{
    Node *current = head;

    while( current )
    {
        if( fwrite( &current->item, sizeof(current->item), 1, file_stream ) != 1 )
        {
            printf( "An error occured while writing data to file.\n" );
            perror( "Error: " );
            exit( 1 );
        }

        current = current->next;
    }
}

void ReadDataFromFile( FILE *file_stream )
{
    Item item;

    while( !feof( file_stream ) )
    {
        int read = fread( &item, sizeof(item), 1, file_stream );
        
        if( feof( file_stream ) != 0 )
        {
            break;
        }

        if( read != 1 )
        {
            printf( "An error occured while trying to read from file\n" );
            perror( "Error: " );
            exit( 1 );
        }
        
        PrintData( item );
    }
}

void PrintData( Item item )
{
        printf( "id : %d\n", item.id );
        printf( "name : %s\n", item.name );
        printf( "brand : %s\n", item.brand );
        printf( "kg: %d\n", item.kg );
        printf( "price : %.2lf\n", item.price );
        printf( "---------------------------------------\n" );
}
