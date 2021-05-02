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

void AddToShop( char *file_path );
void PrintShopItems( char *file_path );
void UpdateSmartphone( char *file_path );
Node *NewItem();
Node *AddSmartphoneToShop( Node *head, Node *new );
Node *RemoveFromShop();
Node *FreeList();
void PrintList( Node *head );
void PrintSpecificSmartphone( Node *head );

int main()
{
  // char file_path[50] = "/tmp/pik_course_work/smartphones_shop.bin";
  // AddToShop( file_path );
  // PrintShopItems( file_path );
  // UpdateSmartphone( file_path );
  // PrintShopItems( file_path );

  Node *head = NULL;
    
  int command = -1;
  while( command != 0 )
  {
      printf( "MENU\n" );
      printf( "0. EXIT\n" );
      //printf("1. CREATE List\n");
      printf( "1. ADD new data\n" );
      //printf("3. Delete picture\n");
      //printf("4. SEARCH by price\n");
      printf( "2. Buy samrtphone\n" );
      printf( "3. PRINT info for all pictures\n" );
      printf( "4. PRINT info for specific smartphone\n" );
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
              //head = TODO
              break;
          case 3:
              PrintList( head );
              break;
          case 4:
              PrintSpecificSmartphone( head );
              break;
      }
  }

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
  if( smartphone.nomenclature_number[strlen( smartphone.nomenclature_number ) - 1] == '\n' )
  {
    smartphone.nomenclature_number[strlen( smartphone.nomenclature_number ) - 1] = '\0';
  }
    
  printf( "model: " );
  fgets(smartphone.model, 20, stdin);
  if( smartphone.model[strlen( smartphone.model ) - 1] == '\n' )
  {
    smartphone.model[strlen( smartphone.model ) - 1] = '\0';
  }

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
  new->next = head;
  head = new;
  return head;
}

void PrintList( Node *head )
{
  Node *current = head;

  while( current )
  {
    printf("nomenclature number: %s\nmodel: %s\nprice: %lf\nquantity: %d\n", current->smartphone.nomenclature_number,
                                                                               current->smartphone.model,
                                                                               current->smartphone.price,
                                                                               current->smartphone.quantity);
    printf("\n-------------------------------\n\n");

    current = current->next;
  }
}

void PrintSpecificSmartphone( Node *head )
{
  Node *current = head;
  char nomenclature_number[12];
  printf("Enter nomenclature number of phone to display: ");
  fgets( nomenclature_number, 12, stdin );
  if( nomenclature_number[strlen( nomenclature_number ) - 1] == '\n' )
  {
    nomenclature_number[strlen( nomenclature_number ) - 1] = '\0';
  }

  while( current )
  {
    if( strcmp( current->smartphone.nomenclature_number, nomenclature_number ) == 0 )
    {
      printf("nomenclature number: %s\nmodel: %s\nprice: %lf\nquantity: %d\n", current->smartphone.nomenclature_number,
                                                                               current->smartphone.model,
                                                                               current->smartphone.price,
                                                                               current->smartphone.quantity);
      printf("\n-------------------------------\n\n");
    }

    current = current->next;
  }
}

Node *FreeList( Node *head )
{
  Node *current = head;
  while(head != NULL)
  {
      head = head -> next;
      free(current);
      current = head;
  }
}

void AddToShop( char *file_path )
{
  FILE *file_stream;
  if( ( file_stream = fopen( file_path, "wb" ) ) == NULL )
  {
    printf( "Cannot open file %s\n", file_path );
    perror( "Error: " );
    exit( 1 );
  }
  
  Smartphone smartphone;
  int smartphones_add_count;
  printf( "Enter number of smartphones to add: " );
  scanf( "%d", &smartphones_add_count );
  getchar();

  for( int i = 0; i < smartphones_add_count; i++ )
  {
    printf( "nomenclature number: " );
    fgets(smartphone.nomenclature_number, 12, stdin);
    if( smartphone.nomenclature_number[strlen( smartphone.nomenclature_number ) - 1] == '\n' )
    {
      smartphone.nomenclature_number[strlen( smartphone.nomenclature_number ) - 1] = '\0';
    }
      
    printf( "model: " );
    fgets(smartphone.model, 20, stdin);
    if( smartphone.model[strlen( smartphone.model ) - 1] == '\n' )
    {
      smartphone.model[strlen( smartphone.model ) - 1] = '\0';
    }

    printf( "price: " );
    scanf( "%lf", &smartphone.price );

    printf( "quantity: " );
    scanf( "%d", &smartphone.quantity );
    getchar(); 
    fwrite( &smartphone, sizeof(smartphone), 1, file_stream );
  }
  
  fclose( file_stream );
  printf( "Succesfully added %d smartphones to the shop.\n", smartphones_add_count );
}

void PrintShopItems( char *file_path )
{
  FILE *file_stream;
  if( ( file_stream = fopen( file_path, "rb" ) ) == NULL )
  {
    printf( "Cannot open file %s\n", file_path );
    perror( "Error: " );
    exit( 1 );
  }

  Smartphone smartphone;
  int smartphones_add_count;
  
  while( 1 )
  {
    fread( &smartphone, sizeof(smartphone), 1, file_stream );

    if( feof( file_stream ) != 0 )
    {
      break;
    }

    printf("nomenclature number: %s\nmodel: %s\nprice: %lf\nquantity: %d\n", smartphone.nomenclature_number,
                                                                               smartphone.model,
                                                                               smartphone.price,
                                                                               smartphone.quantity);
    printf("\n-------------------------------\n\n");
  }

  fclose(file_stream);
}

void UpdateSmartphone( char *file_path )
{
  FILE *file_stream;
  if( ( file_stream = fopen( file_path, "r+b" ) ) == NULL )
  {
    printf( "Cannot open file %s\n", file_path );
    perror( "Error: " );
    exit( 1 );
  }

  Smartphone smartphone;
  while( 1 )
  {
    fread( &smartphone, sizeof( smartphone ), 1, file_stream );

    if( feof( file_stream ) == 1 )
    {
      break;
    }
    
    printf("number: %s\n", smartphone.nomenclature_number);
    if( strcmp( smartphone.nomenclature_number, "12345" ) == 0 )
    {
      smartphone.quantity -= 13;
      fseek( file_stream, ftell( file_stream ) - sizeof( smartphone ), SEEK_SET );
      fwrite( &smartphone, sizeof(smartphone), 1, file_stream );
      break;
    }
  }
  
  fclose(file_stream);
}
