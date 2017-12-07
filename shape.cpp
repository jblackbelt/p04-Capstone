#include <iostream>
#include "bitmap.h"
#include "shape.h"

void Shape::setsides(int s)
{
    sides = s;
}
void Shape::setlength(int l)
{
    length = s;
}
void Shape::setcolor(Bitmap::Pixel p)
{
    color = p;
}
void Shape::setcolor2(Bitmap::Pixel p)
{
    color2 = p;
}
void Shape::setcolor2(int r, int g, int b)
{
    color2.red = r;
    color2.blue = b;
    color2.green = g;
}
void Shape::setcolor(int r, int g, int b)
{
    color.red = r;
    color.blue = b;
    color.green = g
}
void setsize( std::vector < std::vector < Bitmap::Pixel > > &s)
{
    size = s;
}
int getsides()
{
    return sides;
}
int getlength()
{
    return length;
}
Bitmap::Pixel getcolor();
{
    return color;
}
