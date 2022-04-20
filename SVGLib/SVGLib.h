#include <stdint.h>

typedef enum _SVGLIB_RET_T_
{
    SVGLib_ok = 0 ,
    SVGLib_err_handler ,
    SVGLib_err_openFile ,
    SVGLib_err_writeFile
} SVGLibRet_t ;

#define SVGLIB_NOCOLOR                           ( ( uint32_t ) 0xFFFFFFFF )

SVGLibRet_t SVGLib_createHandler( void ** handler , char * fname , uint32_t sizex , uint32_t sizey ) ;

SVGLibRet_t SVGLib_retangle( void * handler , uint32_t x , uint32_t y , uint32_t width , uint32_t height , uint32_t strokeColor , uint32_t stokewidth , uint32_t fillColor ) ;
SVGLibRet_t SVGLib_circle( void * handler , uint32_t x , uint32_t y , uint32_t radius , uint32_t strokeColor , uint32_t stokewidth , uint32_t fillColor ) ;
SVGLibRet_t SVGLib_ellipse( void * handler , uint32_t x , uint32_t y , uint32_t radius_x , uint32_t radius_y , uint32_t strokeColor , uint32_t stokewidth , uint32_t fillColor ) ;
SVGLibRet_t SVGLib_line( void * handler , uint32_t x1 , uint32_t y1 , uint32_t x2 , uint32_t y2 , uint32_t strokeColor , uint32_t stokewidth ) ;

SVGLibRet_t SVGLib_closeHandler( void * handler ) ;
