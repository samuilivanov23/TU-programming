#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Smartphone_Struct Smartphone;
struct Smartphone_Struct {
  char nomenclature_number[12];
  char model[20];
  double price;
  unsigned int quantity;
};

typedef struct Node_Struct Node;
struct Node_Struct {
  Smartphone smartphone;
  Node *next;
};

Node *InitializeList( Node *head, char *file_path );
Node *NewItem();
Node *AddSmartphoneToShop( Node *head, Node *new );
Node *BuySmartphone( Node *head );
void AddQuantity( Node *head );
Node *RemoveSmartphone( Node *head, char *nomenclature_number );
void PrintList( Node *head );
void PrintSpecificSmartphone( Node *head );
void SaveDataToFile( Node *head, char *file_path );
void FreeList( Node *head );
char *RemoveTrailingNL( char *string );

int main()
{
  char file_path[50] = "/tmp/pik_course_work/smartphones_shop.bin";
  Node *head = InitializeList( NULL, file_path );
    
  int command = -1;
  while( command != 0 )
  {
      printf( "MENU\nData is saved to file upon exit to prevent data loss!\n" );
      printf( "0. EXIT\n" );
      printf( "1. ADD new data\n" );
      printf( "2. Buy samrtphone\n" );
      printf( "3. ADD count to existing stock\n" ); 
      printf( "4. PRINT info for all pictures\n" );
      printf( "5. PRINT info for specific smartphone\n" );
      printf("6. SAVE data to file\n");
      printf( "###############\n" );

      printf( "Your command: " );
      scanf( "%d", &command );
      getchar();

      switch( command )
      {
          case 1:
              head = AddSmartphoneToShop( head, NewItem() );
              break;
          case 2:
              head = BuySmartphone( head );
              break;
          case 3:
              AddQuantity( head );
              break;
          case 4:
              PrintList( head );
              break;
          case 5:
              PrintSpecificSmartphone( head );
              break;
          case 6:
              SaveDataToFile( head, file_path );
              break;
      }
  }

  SaveDataToFile( head, file_path );
  FreeList( head );
  return 0;
}

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
    printf( "nomenclature number: %s\nmodel: %s\nprice: %lf\nquantity: %d\n", current->smartphone.nomenclature_number,
                                                                               current->smartphone.model,
                                                                               current->smartphone.price,
                                                                               current->smartphone.quantity );
    printf( "-------------------------------\n\n" );

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
      printf("nomenclature number: %s\nmodel: %s\nprice: %lf\nquantity: %d\n", current->smartphone.nomenclature_number,
                                                                               current->smartphone.model,
                                                                               current->smartphone.price,
                                                                               current->smartphone.quantity);
      printf("-------------------------------\n\n");
    }

    current = current->next;
  }
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
    while ( head && ( strcmp( head->smartphone.nomenclature_number, nomenclature_number ) == 0 ) )
    {  
        printf( "HERE\n" );
        if( !head->next )
        {
          head = NULL;
          free( head );
          return head;
        }
        head = head->next;
        free( head );
    }

    Node* current;
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
