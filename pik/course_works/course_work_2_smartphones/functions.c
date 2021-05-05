#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"

Node *NewItem()
{
  Node *result = NULL;
  result = ( Node * )malloc( sizeof( Node ) );
  Smartphone smartphone;

  printf( "nomenclature number: " );
  fgets(smartphone.nomenclature_number, 12, stdin);
  strcpy( smartphone.nomenclature_number, RemoveTrailingNL( smartphone.nomenclature_number ) );
    
  printf( "model: " );
  fgets(smartphone.model, 20, stdin);
  strcpy( smartphone.model, RemoveTrailingNL( smartphone.model ) );

  printf( "price: " );
  scanf( "%lf", &smartphone.price );

  printf( "quantity: " );
  scanf( "%d", &smartphone.quantity );
  getchar();

  result->smartphone = smartphone;
  result->next = NULL;

  return result;
}

Node *AddSmartphoneToShop( Node *head, Node *new )
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

  printf( "\n-------------------------------\n" );
  while( current )
  {
    PrintData( current->smartphone );
    current = current->next;
  }
}

void PrintSpecificSmartphone( Node *head )
{
  Node *current = head;
  char nomenclature_number[12];
  printf("Enter nomenclature number of phone to display: ");
  fgets( nomenclature_number, 12, stdin );
  strcpy( nomenclature_number, RemoveTrailingNL( nomenclature_number ) );

  printf( "\n-------------------------------\n" );
  while( current )
  {
    if( strcmp( current->smartphone.nomenclature_number, nomenclature_number ) == 0 )
    {
      PrintData( current->smartphone );
    }

    current = current->next;
  }
}

void PrintData( Smartphone smartphone )
{
  printf( "nomenclature number: %s\nmodel: %s\nprice: %lf\nquantity: %d\n", smartphone.nomenclature_number,
                                                                            smartphone.model,
                                                                            smartphone.price,
                                                                            smartphone.quantity );
  printf( "-------------------------------\n\n" );
}

void FreeList( Node *head )
{
  Node *current = head;
  while(head != NULL)
  {
      head = head -> next;
      free(current);
      current = head;
  }
}

Node *InitializeList( Node *head, char *file_path )
{
  FILE *file_stream;
  if( ( file_stream = fopen( file_path, "rb" ) ) == NULL )
  {
    printf( "Cannot open file %s\n", file_path );
    perror( "Error: " );
    return NULL;
  }

  Smartphone smartphone;
  
  while( 1 )
  {
    fread( &smartphone, sizeof(smartphone), 1, file_stream );
    if( feof( file_stream ) != 0 )
    {
      break;
    }
    
    Node *current = ( Node* )malloc( sizeof( Node ) );
    current->smartphone = smartphone;
    head = AddSmartphoneToShop( head, current );
  } 

  fclose( file_stream );
  return head;
}

void SaveDataToFile( Node *head, char *file_path )
{
  FILE *file_stream;
  if ( ( file_stream = fopen( file_path, "wb" ) ) == NULL )
  {
    printf( "Cannot open file %s\n", file_path );
    perror( "Error: " );
    exit(1);
  }

  Node *current = head;
  while( current )
  {
    fwrite( &current->smartphone, sizeof(current->smartphone), 1, file_stream );
    current = current->next;
  }

  fclose( file_stream );
  printf( "Successfully saved data to %s\n", file_path );
}

Node *BuySmartphone( Node *head )
{
  char nomenclature_number[12];
  printf( "Enter nomenclature number of phone to buy: " );
  fgets(nomenclature_number, 12, stdin);
  strcpy( nomenclature_number, RemoveTrailingNL( nomenclature_number ) );

  Node *current = head;
  while( current )
  {
    if( strcmp( current->smartphone.nomenclature_number, nomenclature_number ) == 0 )
    {
      while( 1 )
      {
        unsigned int input_quantity;
        printf( "Enter quantity to buy: " );
        scanf( "%d", &input_quantity );

        printf( "---------------------------------\nsmartphone quantity: %d\nentered quantity: %d\n", current->smartphone.quantity, input_quantity );
        printf( "Diff: %d\n", current->smartphone.quantity - input_quantity );        
        int difference = current->smartphone.quantity - input_quantity;       

        if( difference == 0 )
        {
          head = RemoveSmartphone( head, nomenclature_number );
          break;
        }
        else if( difference > 0 )
        {
          current->smartphone.quantity -= input_quantity;
          break;
        }
        else
        {
          printf( "Not enough quantity in stock. Please chose lesser count.\n" );
        }
      }
    }
    current = current->next;
  }

  return head;
}

Node *RemoveSmartphone( Node *head, char *nomenclature_number )
{
  Node* current;
  while ( head && ( strcmp( head->smartphone.nomenclature_number, nomenclature_number ) == 0 ) )
  {  
    if( !head->next )
    {
      free( head );
      return NULL;
    }
    
    current = head->next;
    free( head );
    head = current;
  }
 
  for( current = head; current != NULL; current = current->next )
  {
    while( current->next != NULL && ( strcmp( current->next->smartphone.nomenclature_number, nomenclature_number ) == 0 ) )
    {
      Node* temp = current->next;
      current->next = temp->next;
      free( temp );
    }
  }

  free( current );
  return head;
}

void AddQuantity( Node *head )
{
  char nomenclature_number[12];
  printf( "Enter nomenclature number of phone to buy: " );
  fgets(nomenclature_number, 12, stdin);
  strcpy( nomenclature_number, RemoveTrailingNL( nomenclature_number ) );

  Node *current = head;
  while( current )
  {
    if( strcmp( current->smartphone.nomenclature_number, nomenclature_number ) == 0 )
    {
      unsigned int input_quantity;
      printf( "Enter quantity to add: " );
      scanf( "%d", &input_quantity );
      
      current->smartphone.quantity += input_quantity;
      break;
    }
    current = current->next;
  }
}

char *RemoveTrailingNL( char *string )
{
  if( string[strlen( string ) - 1] == '\n' )
  {
    string[strlen( string ) - 1] = '\0';
  }

  return string;
}
