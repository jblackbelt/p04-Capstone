#ifndef SHAPE_H
#define SHAPE_H
 
#include <iostream>   
#include <vector>
#include <string>
#include "bitmap.h"
#include <cmath>

class Shape
{
    private:
    int sides;
    int length;
    int width;
    Pixel color;
    Pixel color2;
    std::vector < std::vector < Pixel > > size; 
    int x;
    int y;
    public:
    void recalibrate();
    void setsides(int);
    void setlength(int);
    void getwidth(int);
    void setcolor(Pixel);
    void setcolor2(Pixel);
    void setcolor2(int, int, int);
    void setcolor(int , int , int);
    void setsize( std::vector < std::vector < Pixel > > &); 
    int getsides();
    int getlength();
    Pixel getcolor();
    void getsize(std::vector < std::vector < Pixel > > &);
    Shape();
    Shape(int , int , int, Pixel , Pixel , std::vector < std::vector < Pixel > > &);
};
#endif

