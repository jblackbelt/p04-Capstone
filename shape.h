#ifndef SHAPE_H
#define SHAPE_H
    
#include <vector>
#include <string>
#include "bitmap.h"
#include <cmath>

class Shape
{
    public:
    int sides;
    int length;
    int width;
    Bitmap::Pixel color;
    Bitmap::Pixel color2;
    std::vector < std::vector < Bitmap::Pixel > > size; 
    int x;
    int y;
    void reset();
    private:
    void setsides(int);
    void setlength(int);
    void getwidth(int);
    void setcolor(Bitmap::Pixel);
    void setcolor2(Bitmap::Pixel);
    void setcolor2(int, int, int);
    void setcolor(int , int , int);
    void setsize( std::vector < std::vector < Bitmap::Pixel > > &); 
    int getsides();
    int getlength();
    Bitmap::Pixel getcolor();
    std::vector < std::vector < Bitmap::Pixel > > getfinal(); 
    Shape()
    {
        sides = 3;
        length = 1;
        width = 1;
        color.red = 252;  
        color.green = 252;  
        color.blue = 252;
        color2.red = 0;  
        color2.green = 0;  
        color2.blue = 0;
        size.resize(3, color2);
        for( int i=0; i < size.size() ; i++)
        {
            size[i].resize(3,color);
        }
        x = (size.size()/2);
        y = (size[0].size()/2)-1;
        size[x][y] = color;
        size[x-length][y+length]= color;
        size[x][y+length]= color;
        size[x+length][y+length]= color;
    }
    Shape(int s, int l, int w, Bitmap::Pixel p1, Bitmap::Pixel p2, std::vector < std::vector < Bitmap::Pixel > > &s2)
    {
        sides = s;
        length = l;
        width = w;
        color = p1;
        color2 = p2;
        size = s2;
        for(int i =0; i < size.size(); i++)
        {
            for(int j =0; j < size[i].size(); j++)
            {
                size[i][j] = color2;
            }
        }
        if( size.size() %2 = 0)
        {
            x = (size.size()/2);
        }
        else
        {
            x = (size.size()/2)+1;
        }
        y = (size[0].size()/2);
        y = y - std::nearbyint(/*min posible length*/length/2.0 +/*max posible length*/ 2/std::sqrt(3)/*the # is = (2 *root 3)/3*/*(length/2.0))/2; 
        double degree = (sides-2) * 180;//find degrees in the shape
        degree /= sides;//find degrees per point
        degree /= 2;
        int pointx = x + std::nearbyint(1.0/((1.0/(length/2.0))*std::cos(degree));//find x coord
        int pointy = y + std::nearbyint((std::sin(180 - (degree + 90))/((1.0/length/2.0)*std::cos(degree));//find y coord 
        for( int i=0; i < length/2; i++)
        {
            for( int j=width; j > -width; j--)
            {
                if( sides % 2 = 0)
                {
                    if( length % 2 = 0)
                    {
                        size[x-(i)][y-width] = color;
                        size[x+(i)-1][y-width] = color;
                    
                    }
                    else
                    {
                        size[x-(i)][y-width] = color;
                        size[x+(i)][y-width] = color;
                    }

                }
                else
                {
                    if( length % 2 = 0)
                    {
                        size[x-(i)][y-width] = color;
                        size[x+(i)-1][y-width] = color;
                    
                    }
                    else
                    {
                        size[x-(i)][y-width] = color;
                        size[x+(i)][y-width] = color;
                    }
                }
           }
        }
    }


};
#include "shape.cpp"
#endif

