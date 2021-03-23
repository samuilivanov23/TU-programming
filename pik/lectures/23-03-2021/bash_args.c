//io_files are in the /tmp/pik_io directory

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void ReadPrintFile( char *file_name, char *out_file );
void ReadBinaryWriteTextFile( char *input_file, char *out_file );

int main( int argc, char **argv )
{
    
    if( argc < 2 )
    {
        puts( "Usage: main <file path> [<out file path>]" );
        exit( EXIT_SUCCESS );
    }
    else if ( argc == 2 )
    {
        ReadPrintFile(argv[1], NULL);
    }
    else
    {
        ReadPrintFile(argv[1], argv[2]);
    }

    ReadBinaryWriteTextFile( "/tmp/pik_io/test.bin", "/tmp/pik_io/test2.txt" );

    return 0;
}

void ReadPrintFile( char *file_name, char *out_file )
{
    FILE *file_stream = NULL;
    FILE *file_stream_out = NULL;
    FILE *file_stream_out_txt = NULL;
    char name[1000];
    int c;
    int count = 0;

    if( ( file_stream=fopen( file_name, "r" ) ) == NULL )
    {
        perror( "open file" );
        exit( EXIT_FAILURE );

    }

    if( out_file != NULL )
    {
        strcpy( name, out_file );
        strcat( name, ".txt" );

        if( ( file_stream_out = fopen( out_file, "wb" ) ) == NULL )
        {
            perror( "open file" );
            fclose( file_stream );
            exit( EXIT_FAILURE );
        }

        if( ( file_stream_out_txt = fopen(name, "w" ) ) == NULL )
        {
            perror( "open file txt" );
            fclose( file_stream_out_txt );
            exit( EXIT_FAILURE );
        }
    }

    while( ( c = fgetc( file_stream ) ) != EOF )
    {
        count++;
        if( file_stream_out != NULL )
        {
            if( fwrite(&c, sizeof(char), 1, file_stream_out) != 1 )
            {
                perror( "write error" );
                fclose( file_stream );
                fclose( file_stream_out );
                exit( EXIT_FAILURE );
            }

            if( fputc( c, file_stream_out_txt ) == EOF )
            {
                perror("write txt error");
                fclose( file_stream );
                fclose( file_stream_out );
                fclose( file_stream_out_txt );
                exit( EXIT_FAILURE );
            }
        }
        else
        {
            putchar( c );
        }
    }

    fclose( file_stream );
    if( out_file != NULL )
    {
        printf( "\n%d\n", count );
        fwrite( &count, sizeof(int), 1, file_stream_out );
        fprintf( file_stream_out_txt, "\n%d\n", count );
        fclose( file_stream_out );
    }
    else
    {
        printf( "\n%d\n", count );
    }
}

void ReadBinaryWriteTextFile( char *input_file, char *out_file )
{
    FILE *file_stream_input, *file_stream_output;
    char c;

    if( ( file_stream_input = fopen( input_file, "rb" ) ) == NULL )
    {
        perror( "open bin error" );
        exit( EXIT_FAILURE );
    }

    if( ( file_stream_output = fopen( out_file, "w" ) ) == NULL )
    {
        perror( "open txt error" );
        exit( EXIT_FAILURE );
    }

    while( 1 )
    {
        if( fread( &c, sizeof(char), 1, file_stream_input ) != 1 )
        {
            if( feof( file_stream_input ) )
            {
                break;
            }
            else
            {
                perror( "read bin error" );
                fclose( file_stream_input );
                fclose( file_stream_output );
                exit( EXIT_FAILURE );
            }
        }

        if( fputc( c, file_stream_output ) == EOF )
        {
            perror( "read bin error" );
            fclose( file_stream_input );
            fclose( file_stream_output );
            exit( EXIT_FAILURE );
        }
    }
}