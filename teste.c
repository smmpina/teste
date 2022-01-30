#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <locale.h>

void imp_double( double num, int tam, int dec );
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


void imp_double( double num, int tam, int dec )
{
    int i;
    char orig[ 60 ];
    char dest[ 60 ];
    char *po;
    char *pd = dest;

    sprintf( orig, "%#*.*lf", tam, dec, num );

    po = orig;

    while( *po ) po++;

    for( po--; isdigit( *po ); po--, pd++ ) *pd = *po;

    for( i = 0; po >= orig; i++, pd++, po-- )
    {
        if( i == 4 )
        {
            *pd++ = isspace( *po ) ? ' ' : '.';
            i = 1;
        }

        *pd = *po;
    }

    *pd = '\0';

    inverte( dest );

    printf( "%s", dest );
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
