#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

/**
* main - Entry point
* @argc: input function argument
* @argv: input function argument
* Return: 0
*/

int main( int argc, char *argv[] )
{
    long result = 1;
    int i;

    for (i = 1; i < argc; i++ )
    {
        long num;
        char *p;


        errno = 0;
        num = strtol( argv[i], &p, 10 );


        if ( p == argv[i] )
        {
            fprintf( stderr, "Conversion of argv[%d] failed!\n", i );
            exit( EXIT_FAILURE );
        }


        if ( errno == ERANGE )
        {
            fprintf( stderr, "Argument of argv[%d] out of range!\n", i );
            exit( EXIT_FAILURE );
        }


        result = result * num;
    }


    printf( "%ld\n", result );
    
    (void)argv;

    return EXIT_SUCCESS;
}
