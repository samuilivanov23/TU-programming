#include <stdio.h>
#include <stdlib.h>

enum boolean{ false, true };

boolean ReadTextFile( FILE *file_stream, char buffer[][1000] );
void FreeMemory( char ***memory, int length );

int main()
{
    char buffer[2][1000];
    FILE *file_stream = fopen( "data.txt", "r+" );
    long position;

    if( file_stream == NULL )
    {
        perror( "open error" );
        return ( EXIT_FAILURE );
    }

    while( true )
    {
        position = ftell(file_stream);
        if( !ReadTextFile( file_stream, buffer ) )
        {
            break;
        }

        fseek( file_stream, position, SEEK_SET );
        fputs( buffer[1], file_stream );
        fputs( buffer[0], file_stream );
        fseek( file_stream, 0L, SEEK_SET );
    }

    fclose( file_stream );

    return 0;
}

boolean ReadTextFile( FILE *file_stream, char buffer[][1000] )
{
    int i;

    if(buffer = ( char** )malloc( 2*sizeof( char* ) ) == NULL )
    {
        perror( "malloc char** error" );
        return 0;
    }

    if( fgets( buffer[0], 1000, file_stream ) == NULL )
    {
        if( !feof( file_stream ) )
        {
            perror( "read odd LINE error" );
        }

        return false;

    }

    if( fgets( buffer[1], 1000, file_stream ) == NULL )
    {
        if( !feof( file_stream ) )
        {
            perror( "read even LINE error" );
        }
        
        return false;
    }

    puts( buffer[0] );
    puts( buffer[1] );

    return true;
}

void FreeMemory( char ***memory, int length )
{
    int i;

    for( i = 0; i < length; i++ )
    {
        free( (*memory)[i] );
        memory[i] = NULL;
    }

    free(*memory);
    *memory = NULL;
}
