#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"

//Generates a new smartphones
Node *NewItem( Node *head )
{
  Node *result = NULL;
  result = ( Node * )malloc( sizeof( Node ) );
  Smartphone smartphone;

  //Reads data from user
  while( 1 )
  {
    printf( "nomenclature number: " );
    fgets(smartphone.nomenclature_number, NOMENCLATURE_NUMBER_SIZE, stdin);
    strcpy( smartphone.nomenclature_number, RemoveTrailingNL( smartphone.nomenclature_number ) );
    int is_unique = IsNomenclatureNumberUnique( head, smartphone.nomenclature_number );

    //checks for nomenclature_number_size - 1 because the last char (13th char) is the zero '\0' character
    if( ( strlen( smartphone.nomenclature_number ) == NOMENCLATURE_NUMBER_SIZE - 1 ) )
    {
      getchar();

      if( is_unique )
      {
        break;
      }
    }
    else
    {
      printf( "Please enter 12 character nomenclature number.\n" );
    }
  }

  printf( "model: " );
  fgets(smartphone.model, MODEL_SIZE, stdin);
  if( strlen( smartphone.model ) == MODEL_SIZE )
  {
    getchar();
  }
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

//Adds a new phone to the list
Node *AddSmartphoneToShop( Node *head, Node *new )
{
  //If there is a head node -> adds the new node on top of it
  if( head != NULL )
  {  
    new->next = head;
  }

  //Updates the head node to be the first in the list
  head = new;
  return head;
}

//Prints the entire list
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

//Prints information for a specific smartphone
void PrintSpecificSmartphone( Node *head )
{
  Node *current = head;
  char nomenclature_number[NOMENCLATURE_NUMBER_SIZE];
  
  //Takes input from user
  printf("Enter nomenclature number of phone to display: ");
  fgets( nomenclature_number, NOMENCLATURE_NUMBER_SIZE, stdin );
  strcpy( nomenclature_number, RemoveTrailingNL( nomenclature_number ) );

  printf( "\n-------------------------------\n" );
  //loops through the list
  while( current )
  {
    //checks for the matching node and prints its data
    if( strcmp( current->smartphone.nomenclature_number, nomenclature_number ) == 0 )
    {
      PrintData( current->smartphone );
    }

    current = current->next;
  }
}

//Prints the data for a single smartphone
void PrintData( Smartphone smartphone )
{
  printf( "nomenclature number: %s\nmodel: %s\nprice: %lf\nquantity: %d\n", smartphone.nomenclature_number,
                                                                            smartphone.model,
                                                                            smartphone.price,
                                                                            smartphone.quantity );
  printf( "-------------------------------\n\n" );
}

//Loops through the list and frees  the allocated memory for every node
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

//Reads the database file and buffers the data into the linked list
Node *InitializeList( Node *head, char *file_path )
{
  FILE *file_stream;

  //Opens the file
  //if the file can not be opened => returns null and the list is empty at the beginning of the session.
  if( ( file_stream = fopen( file_path, "rb" ) ) == NULL )
  {
    printf( "Cannot open file %s\n", file_path );
    perror( "Error: " );
    return NULL;
  }

  Smartphone smartphone;
  
  //loops through the end of file and read the data, structure by structure
  while( 1 )
  {
    int read = fread( &smartphone, sizeof(smartphone), 1, file_stream );
    
    if( feof( file_stream ) != 0 )
    {
      break;
    }
    
    if( read != 1 )
    {
      printf( "An error occurred while trying to read from file.\n" );
      perror( "Error: " );
      exit( 1 );
    }

    //allocates memory for the current node and adds it to the list
    Node *current = ( Node* )malloc( sizeof( Node ) );
    current->smartphone = smartphone;
    head = AddSmartphoneToShop( head, current );
  }

  //closes the opened file stream
  fclose( file_stream );
  return head;
}

//Saves the buffer (list data) to the database file
void SaveDataToFile( Node *head, char *file_path )
{
  FILE *file_stream;

  //Opens the file
  //if the file cannot be opened the, an error mesage is printed
  //and the application sends SIGTERM signal to close the process. Data is lost.
  if ( ( file_stream = fopen( file_path, "wb" ) ) == NULL )
  {
    printf( "Cannot open file %s\n", file_path );
    perror( "Error: " );
    exit(1);
  }

  //loops through the list and writes the data to the file
  Node *current = head;
  while( current )
  {
    if( fwrite( &current->smartphone, sizeof(current->smartphone), 1, file_stream ) != 1 )
    {
      printf( "An error occurred while trying to write to file.\n" );
    }
    current = current->next;
  }

  //closes the opened file stream 
  fclose( file_stream );
  printf( "Successfully saved data to %s\n", file_path );
}

//Simulates buying a smartphone by changing its quantity
Node *BuySmartphone( Node *head )
{
  char nomenclature_number[NOMENCLATURE_NUMBER_SIZE];

  //Takes input from user

  while( 1 )
  {
    printf( "Enter nomenclature number of phone to buy: " );
    fgets(nomenclature_number, NOMENCLATURE_NUMBER_SIZE, stdin);
    strcpy( nomenclature_number, RemoveTrailingNL( nomenclature_number ) );
    
    if( !IsNomenclatureNumberUnique( head, nomenclature_number ) )
    {
      break;
    }
    else
    {
      printf( "A phone with this nomenclature number does not exist. Enter an existing one.\n" );
      getchar();
    }
  }

  Node *current = head;

  //loops through the list and checks for matching node
  while( current )
  {
    if( strcmp( current->smartphone.nomenclature_number, nomenclature_number ) == 0 )
    {
      //loops until a valid operation is performed
      while( 1 )
      {
        unsigned int input_quantity;

        //Takes input from user
        printf( "Enter quantity to buy: " );
        scanf( "%d", &input_quantity );

        printf( "---------------------------------\nsmartphone quantity: %d\nentered quantity: %d\n", current->smartphone.quantity, input_quantity );
        printf( "Diff: %d\n", current->smartphone.quantity - input_quantity );        
        int difference = current->smartphone.quantity - input_quantity;       

        //if entered quantity is equal to the current quantity of the smartphone
        // --> the smartphone is removed from the shop (list)
        if( difference == 0 )
        {
          head = RemoveSmartphone( head, nomenclature_number );
          break;
        }
        //if entered quantity is lower than the current quantity of the smartphone
        // --> smartphone current quantity is updated
        else if( difference > 0 )
        {
          current->smartphone.quantity -= input_quantity;
          break;
        }
        //if entered quantity is greated than the current quantity of the smartphone
        // --> error message for not enough quantity in stock is displayed. Nothing is executed this case.
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

//Removes a given smarthone from the list
Node *RemoveSmartphone( Node *head, char *nomenclature_number )
{
  Node* current;

  //Remove the head if it matches the nomenclature number
  while ( head && ( strcmp( head->smartphone.nomenclature_number, nomenclature_number ) == 0 ) )
  {  
    //if head is the only node in the list => free the head and return NULL 
    //as the list will be empty at this point
    if( !head->next )
    {
      free( head );
      return NULL;
    }
    
    //Use the current variable to store the head next node 
    //and then reassign the head to the current node after freeing memory
    current = head->next;
    free( head );
    head = current;
  }
 
  //Remove middle nodes
  //outer loop to move the head forward
  for( current = head; current != NULL; current = current->next )
  {
    //inner loop to check if current node next matches the nomenclature number => will be removed
    while( current->next != NULL && ( strcmp( current->next->smartphone.nomenclature_number, nomenclature_number ) == 0 ) )
    {
      //Use the temp variable to store the current next node to the free memory allocated for the matched node 
      Node* temp = current->next;
      current->next = temp->next;
      free( temp );
    }
  }

  return head;
}

//Add quantity to a specified smartphone
void AddQuantity( Node *head )
{
  //Take input from the user
  char nomenclature_number[NOMENCLATURE_NUMBER_SIZE];
  printf( "Enter nomenclature number of phone to buy: " );
  fgets(nomenclature_number, NOMENCLATURE_NUMBER_SIZE, stdin);
  strcpy( nomenclature_number, RemoveTrailingNL( nomenclature_number ) );

  Node *current = head;
  
  //Loops through the list to find matching node
  while( current )
  {
    //checks for node with matching nomenclature number
    if( strcmp( current->smartphone.nomenclature_number, nomenclature_number ) == 0 )
    {
      //Take input for quantity to be bought
      unsigned int input_quantity;
      printf( "Enter quantity to add: " );
      scanf( "%d", &input_quantity );
      
      //modifies current node quantity based on the inputted data
      current->smartphone.quantity += input_quantity;
      break;
    }

    current = current->next;
  }
}

//Removes the trailing new line characters from string inputed with fgets
char *RemoveTrailingNL( char *string )
{
  if( strlen( string ) > 0 && string[strlen( string ) - 1] == '\n' )
  {
    string[strlen( string ) - 1] = '\0';
  }

  return string;
}

//Checks if there is already a smartphone with the entered nomenclature number in the list
//if so -> the user should enter unique nomenclature number
int IsNomenclatureNumberUnique( Node *head, char *nomenclature_number )
{
  Node *current = head;

  while( current )
  {
    if( strcmp( current->smartphone.nomenclature_number, nomenclature_number ) == 0 )
    {
      printf( "A phone with this nomenclature number already exists.\n" );
      return 0;
    }

    current = current->next;
  }

  return 1;
}
