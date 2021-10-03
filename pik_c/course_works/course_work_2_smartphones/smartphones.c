#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"

int main()
{
  Node *head = InitializeList( NULL, FILE_PATH );
    
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
              head = AddSmartphoneToShop( head, NewItem( head ) );
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
              SaveDataToFile( head, FILE_PATH );
              break;
		      default:
		        if( command != 0 )
			      {
			        printf( "Please enter a valid option (from 0 to 6).\n" );
			      }
			      break;
      }
  }

  SaveDataToFile( head, FILE_PATH );
  FreeList( head );
  return 0;
}
