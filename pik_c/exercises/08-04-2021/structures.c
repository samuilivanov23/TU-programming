#include <stdio.h>
#include <stdlib.h>

struct Box {
  int width;
  int length;
  int height;
  int volume;
};

void PrintBox( struct Box box);
void PrintReverseBox( struct Box* boxes, unsigned length );
void ProcessBoxes( struct Box* boxes, unsigned length );
void SortArray(struct Box *boxes, unsigned length );
void Swap( int *x, int *y );

int main()
{
  struct Box boxes[3];
  
  for(int i = 0; i < 3; i++)
  {
    printf("width: ");
    scanf("%d", &boxes[i].width);
    
    printf("length: ");
    scanf("%d", &boxes[i].length);    
    
    printf("height: ");
    scanf("%d", &boxes[i].height);
    boxes[i].volume = boxes[i].width * boxes[i].length * boxes[i].height;
  }
  
  ProcessBoxes(boxes, 3);

  return 0;
}

void PrintBox( struct Box box )
{
  printf( "width: %d\n", box.width );
  printf( "length: %d\n", box.length );
  printf( "height: %d\n", box.height );
  
  box.volume = box.width * box.length * box.height;
  printf( "volume: %d\n", box.volume );
}

void PrintReverseBox( struct Box *boxes, unsigned length )
{
  for( int i = 0; i < length; i++ )
  {
    printf( "width [%d]: %d\n", i, boxes[i].width );
  }
}

void ProcessBoxes( struct Box *boxes, unsigned length )
{
  SortArray(boxes, length);
  
  printf( "larger: %d\n", boxes[length].volume );
  printf( "smallest: %d\n", boxes[0].volume );
}

void SortArray( struct Box *boxes, unsigned length )
{
  int i, j, min_index;

  for ( int i = 0; i < length - 1; i++ )
  {
    min_index = i;
    for ( j = i + 1; j < length; j++ )
    {
      if( boxes[i].volume < boxes[min_index].volume )
      {
        min_index = j;  
      }

      printf( "%d %d\n", boxes[min_index].volume, boxes[i].volume );  
      Swap( &boxes[min_index].volume, &boxes[i].volume );
      printf( "%d %d\n", boxes[min_index].volume, boxes[i].volume );   
    }
  }

  //printf( "larger: %d\n", boxes[length].volume );
  //printf( "smallest: %d\n", boxes[0].volume );
}

void Swap( int *x, int *y )
{
  *x = *x ^ *y;
  *y = *x ^ *y;
  *x = *x ^ *y;
}
