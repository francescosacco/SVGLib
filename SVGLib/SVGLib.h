/**
 * @file SVGLib.h
 * @author Francesco Sacco
 * @date 19 Apr 2022
 * @brief Library to create basic shapes in SVG files.
 *
 * This library will allow you create SVG files with basic
 * shapes, like retangle, circles and lines.
 *
 * @see http://github.com/francescosacco/SVGLib
 **/
#ifndef SVGLIB_H
#define SVGLIB_H

#include <stdint.h>

#ifdef __cplusplus
    extern "C" {
#endif

typedef enum _SVGLIB_RET_T_
{
    SVGLib_ok = 0 ,
    SVGLib_err_handler ,
    SVGLib_err_openFile ,
    SVGLib_err_writeFile
} SVGLibRet_t ;

#define SVGLIB_NOCOLOR                           ( ( uint32_t ) 0xFFFFFFFF )

/**
 * @brief Creates a handler to work.
 *
 * This function creates a file and defines the basic area to work. It
 * gives a handler to be used.
 *
 * @param [out] handler This output variable is the handler to the SVG.
 * @param [in] fname    String with the file name to be created. If it already exists, the library will overwrite the file.
 * @param [in] sizex    Size of X axis in pixels.
 * @param [in] sizey    Size of Y axis in pixels.
 * @return Error code, based in the SVGLibRet_t enumeration type.
 **/
SVGLibRet_t SVGLib_createHandler( void ** handler , char * fname , uint32_t sizex , uint32_t sizey ) ;

/**
 * @brief Creates a retangle.
 *
 * This function creates a retangle, starting in the x,y position,
 * with the width,height size in pixels.
 *
 * @param [in] handler      Handler of the SVG file.
 * @param [in] x            X position in pixels.
 * @param [in] y            Y position in pixels.
 * @param [in] width        X axis size of the retangle.
 * @param [in] Height       Y axis size of the retangle.
 * @param [in] strokeColor  Color in RGB (24 bits), or SVGLIB_NOCOLOR for no color.
 * @param [in] strokeWidth  Size of the stroke, in pixels.
 * @param [in] fillColor    Color in RGB (24 bits), or SVGLIB_NOCOLOR for no color.
 * @return Error code, based in the SVGLibRet_t enumeration type.
 **/
SVGLibRet_t SVGLib_retangle( void * handler , uint32_t x , uint32_t y , uint32_t width , uint32_t height , uint32_t strokeColor , uint32_t strokeWidth , uint32_t fillColor ) ;

/**
 * @brief Creates a circle.
 *
 * This function creates a circle, starting in the x,y position,
 * with the radius size in pixels.
 *
 * @param [in] handler      Handler of the SVG file.
 * @param [in] x            X position in pixels.
 * @param [in] y            Y position in pixels.
 * @param [in] radius       Radius size of the circle, in pixels.
 * @param [in] strokeColor  Color in RGB (24 bits), or SVGLIB_NOCOLOR for no color.
 * @param [in] strokeWidth  Size of the stroke, in pixels.
 * @param [in] fillColor    Color in RGB (24 bits), or SVGLIB_NOCOLOR for no color.
 * @return Error code, based in the SVGLibRet_t enumeration type.
 **/
SVGLibRet_t SVGLib_circle( void * handler , uint32_t x , uint32_t y , uint32_t radius , uint32_t strokeColor , uint32_t strokeWidth , uint32_t fillColor ) ;

/**
 * @brief Creates an ellipse.
 *
 * This function creates an ellipse, starting in the x,y position,
 * with the x radius and y radius size in pixels.
 *
 * @param [in] handler      Handler of the SVG file.
 * @param [in] x            X position in pixels.
 * @param [in] y            Y position in pixels.
 * @param [in] radius_x     X Radius size of the circle, in pixels.
 * @param [in] radius_y     Y Radius size of the circle, in pixels.
 * @param [in] strokeColor  Color in RGB (24 bits), or SVGLIB_NOCOLOR for no color.
 * @param [in] strokeWidth  Size of the stroke, in pixels.
 * @param [in] fillColor    Color in RGB (24 bits), or SVGLIB_NOCOLOR for no color.
 * @return Error code, based in the SVGLibRet_t enumeration type.
 **/
SVGLibRet_t SVGLib_ellipse( void * handler , uint32_t x , uint32_t y , uint32_t radius_x , uint32_t radius_y , uint32_t strokeColor , uint32_t strokeWidth , uint32_t fillColor ) ;

/**
 * @brief Creates a line.
 *
 * This function creates a line, starting in the x1,y1 position,
 * and finishing in x2,y2 position.
 *
 * @param [in] handler      Handler of the SVG file.
 * @param [in] x1           X start position, in pixels.
 * @param [in] y1           Y start position, in pixels.
 * @param [in] x2           X finish position, in pixels.
 * @param [in] y2           Y finish position, in pixels.
 * @param [in] strokeColor  Color in RGB (24 bits), or SVGLIB_NOCOLOR for no color.
 * @param [in] strokeWidth  Size of the stroke, in pixels.
 * @param [in] fillColor    Color in RGB (24 bits), or SVGLIB_NOCOLOR for no color.
 * @return Error code, based in the SVGLibRet_t enumeration type.
 **/
SVGLibRet_t SVGLib_line( void * handler , uint32_t x1 , uint32_t y1 , uint32_t x2 , uint32_t y2 , uint32_t strokeColor , uint32_t strokeWidth ) ;

/**
 * @brief Creates a text.
 *
 * This function creates a text, starting in the x,y position,
 * with the font and size defined.
 *
 * @param [in] handler      Handler of the SVG file.
 * @param [in] x            X start position, in pixels.
 * @param [in] y            Y start position, in pixels.
 * @param [in] font         Font name, eg. "Arial" or "Courier".
 * @param [in] fontSize     Font size.
 * @param [in] fillColor    Text color in RGB (24 bits).
 * @param [in] text         String with the text to be printed.
 * @return Error code, based in the SVGLibRet_t enumeration type.
 **/
SVGLibRet_t SVGLib_text( void * handler , uint32_t x , uint32_t y , char * font , uint32_t fontSize , uint32_t fillColor , char * text ) ;

/**
 * @brief Close the handler.
 *
 * This function close and save the handler data.
 *
 * @param [in] handler      Handler of the SVG file.
 * @return Error code, based in the SVGLibRet_t enumeration type.
 **/
SVGLibRet_t SVGLib_closeHandler( void * handler ) ;

#ifdef __cplusplus
    }
#endif

#endif // SVGLIB_H
