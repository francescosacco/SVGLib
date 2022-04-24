#include "SVGLib.h"

#include <stdio.h>

#define SVGLIB_COLORMASK(x)                      ( x & 0x00FFFFFF )

SVGLibRet_t SVGLib_createHandler( void ** handler , char * fname , uint32_t sizex , uint32_t sizey )
{
    FILE * file ;
    SVGLibRet_t ret ;
    
    file = fopen( fname , "w" ) ;
    if( ( ( FILE * ) NULL ) != file )
    {
        *handler = ( void * ) file ;

        fprintf( file , "<?xml version=\"1.0\" encoding=\"UTF-8\" standalone=\"no\"?>\n" ) ;
        fprintf( file , "<!DOCTYPE svg PUBLIC \"-//W3C//DTD SVG 1.1//EN\" \"http://www.w3.org/Graphics/SVG/1.1/DTD/svg11.dtd\">\n" ) ;
        fprintf( file , "<svg width=\"%u\" height=\"%u\" viewBox=\"0 0 %u %u\" xmlns=\"http://www.w3.org/2000/svg\" xmlns:xlink=\"http://www.w3.org/1999/xlink\">\n" , sizex , sizey , sizex , sizey ) ;

        ret = SVGLib_ok ;
    }
    else
    {
        *handler = NULL ;
        ret = SVGLib_err_openFile ;
    }
    
    return( ret ) ;
}

SVGLibRet_t SVGLib_retangle( void * handler , uint32_t x , uint32_t y , uint32_t width , uint32_t height , uint32_t strokeColor , uint32_t strokeWidth , uint32_t fillColor )
{
    SVGLibRet_t ret ;
    FILE * file ;
    
    if( NULL != handler )
    {
        file = ( FILE * ) handler ;
        
        fprintf( file , "    <rect x=\"%u\" y=\"%u\" width=\"%u\" height=\"%u\" stroke-width=\"%u\" " , x , y , width , height , strokeWidth ) ;

        if( SVGLIB_NOCOLOR != fillColor )
        {
            fprintf( file , "fill=\"#%06X\" " , SVGLIB_COLORMASK( fillColor ) ) ;
        }

        if( SVGLIB_NOCOLOR != strokeColor )
        {
            fprintf( file , "stroke=\"#%06X\" " , SVGLIB_COLORMASK( strokeColor ) ) ;
        }
        
        fprintf( file , "/>\n" ) ;

        ret = SVGLib_ok ;
    }
    else
    {
        ret = SVGLib_err_handler ;
    }

    return( ret ) ;
}


SVGLibRet_t SVGLib_circle( void * handler , uint32_t x , uint32_t y , uint32_t radius , uint32_t strokeColor , uint32_t strokeWidth , uint32_t fillColor )
{
    SVGLibRet_t ret ;
    FILE * file ;
    
    if( NULL != handler )
    {
        file = ( FILE * ) handler ;
        
        fprintf( file , "    <circle cx=\"%u\" cy=\"%u\" r=\"%u\" stroke-width=\"%u\" " , x , y , radius , strokeWidth ) ;

        if( SVGLIB_NOCOLOR != fillColor )
        {
            fprintf( file , "fill=\"#%06X\" " , SVGLIB_COLORMASK( fillColor ) ) ;
        }

        if( SVGLIB_NOCOLOR != strokeColor )
        {
            fprintf( file , "stroke=\"#%06X\" " , SVGLIB_COLORMASK( strokeColor ) ) ;
        }
        
        fprintf( file , "/>\n" ) ;

        ret = SVGLib_ok ;
    }
    else
    {
        ret = SVGLib_err_handler ;
    }

    return( ret ) ;
}

SVGLibRet_t SVGLib_ellipse( void * handler , uint32_t x , uint32_t y , uint32_t radius_x , uint32_t radius_y , uint32_t strokeColor , uint32_t strokeWidth , uint32_t fillColor )
{
    SVGLibRet_t ret ;
    FILE * file ;
    
    if( NULL != handler )
    {
        file = ( FILE * ) handler ;
        
        fprintf( file , "    <ellipse cx=\"%u\" cy=\"%u\" rx=\"%u\" ry=\"%u\" stroke-width=\"%u\" " , x , y , radius_x , radius_y , strokeWidth ) ;

        if( SVGLIB_NOCOLOR != fillColor )
        {
            fprintf( file , "fill=\"#%06X\" " , SVGLIB_COLORMASK( fillColor ) ) ;
        }

        if( SVGLIB_NOCOLOR != strokeColor )
        {
            fprintf( file , "stroke=\"#%06X\" " , SVGLIB_COLORMASK( strokeColor ) ) ;
        }
        
        fprintf( file , "/>\n" ) ;

        ret = SVGLib_ok ;
    }
    else
    {
        ret = SVGLib_err_handler ;
    }

    return( ret ) ;
}


SVGLibRet_t SVGLib_line( void * handler , uint32_t x1 , uint32_t y1 , uint32_t x2 , uint32_t y2 , uint32_t strokeColor , uint32_t strokeWidth )
{
    SVGLibRet_t ret ;
    FILE * file ;
    
    if( NULL != handler )
    {
        file = ( FILE * ) handler ;
        
        fprintf( file , "    <line x1=\"%u\" y1=\"%u\" x2=\"%u\" y2=\"%u\" stroke-width=\"%u\" " , x1 , y1 , x2 , y2 , strokeWidth ) ;

        if( SVGLIB_NOCOLOR != strokeColor )
        {
            fprintf( file , "stroke=\"#%06X\" " , SVGLIB_COLORMASK( strokeColor ) ) ;
        }
        
        fprintf( file , "/>\n" ) ;

        ret = SVGLib_ok ;
    }
    else
    {
        ret = SVGLib_err_handler ;
    }

    return( ret ) ;
}

SVGLibRet_t SVGLib_text( void * handler , uint32_t x , uint32_t y , char * font , uint32_t fontSize , uint32_t fillColor , char * text )
{
    SVGLibRet_t ret ;
    FILE * file ;
    
    if( NULL != handler )
    {
        file = ( FILE * ) handler ;

        fprintf( file , "    <text x=\"%u\" y=\"%u\" font-family=\"%s\" font-size=\"%u\" " , x , y , font , fontSize ) ;
        if( SVGLIB_NOCOLOR != fillColor )
        {
            fprintf( file , "fill=\"#%06X\" " , SVGLIB_COLORMASK( fillColor ) ) ;
        }
        fprintf( file , ">" ) ;
                
        fprintf( file , "%s" , text ) ;
        fprintf( file , "</text>\n" ) ;

        ret = SVGLib_ok ;
    }
    else
    {
        ret = SVGLib_err_handler ;
    }

    return( ret ) ;
}

SVGLibRet_t SVGLib_closeHandler( void * handler )
{
    SVGLibRet_t ret ;
    FILE * file ;
    
    if( NULL != handler )
    {
        file = ( FILE * ) handler ;

        fprintf( file , "</svg>\n" ) ;
        fclose( file ) ;

        ret = SVGLib_ok ;
    }
    else
    {
        ret = SVGLib_err_handler ;
    }
    
    
    return( ret ) ;
}
