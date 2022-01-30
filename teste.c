#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <locale.h>

void inverte( char *str );
void imp_num( double num, int largura, int precisao, int alinh );

int main()
{
    double d = 1539300.259;

    setlocale( LC_ALL, "" );

    imp_num( d, 15, 2, 0 );

    printf( "\n" );

    return 0;
}

void imp_num( double num, int largura, int precisao, int alinh )
{
    char orig[ 80 ];
    char dest[ 80 ];
    char deci[ 80 ];
    char *po;
    char *pd = dest;
    char *p;
    int count;

    sprintf( orig, "%*d", largura, ( int )num );
    sprintf( deci, "%.*f", precisao, num - ( int )num );

    if( !( p = strstr( deci, "," ) ) ) p = strstr( deci, "." ); 
    
    inverte( orig );
    
    po = orig;

    while( *po++ ) if( isspace( *po ) ) break;

    *po = '\0';

    count = 0;

    po = orig;

    while( *po )
    {
        if( count == 3 )
        {
            *pd = '.';
            pd++;
            count = 0;
        }

        *pd++ = *po++;
        count++;
    }

    *pd = '\0';

    inverte( dest );

    strcat( dest, p );

    alinh ? printf( "%-*s", largura, dest ) :
            printf( "%*s", largura, dest ) ;
}

void inverte( char *str )
{
    char *ini, *fim;
    char c;

    ini = fim = str;

    while( *fim ) fim++;

    for( fim--; ini <= fim; ini++, fim-- )
    {
        c = *ini;
        *ini = *fim;
        *fim = c;
    }
}
