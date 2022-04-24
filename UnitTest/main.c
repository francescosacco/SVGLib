#include <stdio.h>
#include <SVGLib.h>

#define ERROR_CHECK(x)                           if( ret == SVGLib_ok ) {      \
                                                     printf( "[  OK   ]\n" ) ; \
                                                 }                             \
                                                 else {                        \
                                                     printf( "[ ERROR ]\n" ) ; \
                                                     return( -1 ) ;            \
                                                 }


int main( void )
{
    void * handler ;
    SVGLibRet_t ret ;
    
    printf( "UnitTest SVGLib\n" ) ;
    
    printf( "\tCreating a handler  " ) ;
    
    ret = SVGLib_createHandler( &handler , "unitTest.svg" , 1000 , 1000 ) ;
    ERROR_CHECK(ret) ;

    printf( "\tCreating a retangle " ) ;
    ret = SVGLib_retangle( handler , 1 , 1 , 998 , 998 , 0x000000 , 2 , 0xFFFFFF ) ;
    ERROR_CHECK(ret) ;

    printf( "\tCreating a retangle " ) ;
    ret = SVGLib_retangle( handler , 10 , 10 , 100 , 100 , 0xFF0000 , 5 , 0x00FF00 ) ;
    ERROR_CHECK(ret) ;

    printf( "\tCreating a circle   " ) ;
    ret = SVGLib_circle( handler , 150 , 200 , 40 , 0x000000 , 2 , SVGLIB_NOCOLOR ) ;
    ERROR_CHECK(ret) ;

    printf( "\tCreating an ellipse " ) ;
    ret = SVGLib_ellipse( handler , 150 , 300 , 10 , 20 , 0x0000FF , 1 , 0xFFFF00 ) ;
    ERROR_CHECK(ret) ;

    printf( "\tCreating a line     " ) ;
    ret = SVGLib_line( handler , 10 , 350 , 400 , 450 , 0x000000 , 5 ) ;
    ERROR_CHECK(ret) ;

    printf( "\tCreating a text     " ) ;
    ret = SVGLib_text( handler , 10 , 550 , "Arial" , 16 , 0x0000FF , "Hello SVG World!" ) ;
    ERROR_CHECK(ret) ;

    printf( "\tClosing handler     " ) ;
    ret = SVGLib_closeHandler( handler ) ;
    ERROR_CHECK(ret) ;

    return( 0 ) ;
}