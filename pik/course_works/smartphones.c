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

void AddToShop( char *file_path );
void PrintShopItems( char *file_path );
void UpdateSmartphone( char *file_path );

int main()
{
  char file_path[50] = "/tmp/pik_course_work/smartphones_shop.bin";
  AddToShop( file_path );
  PrintShopItems( file_path );
  UpdateSmartphone( file_path );
  PrintShopItems( file_path );
  return 0;
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
