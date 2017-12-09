#include "shape.h"

void Shape::setsides(int s)
{
    sides = s;
}
void Shape::setlength(int l)
{
    length = l;
}
void Shape::setcolor(Pixel p)
{
    color = p;
}
void Shape::setcolor2(Pixel p)
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
    color.green = g;
}
void Shape::setsize( std::vector < std::vector < Pixel > > &s)
{
    size = s;
}
void Shape::getsize(std::vector < std::vector < Pixel > > &s)
{
    s = size;
}
int Shape::getsides()
{
    return sides;
}
int Shape::getlength()
{
    return length;
}
Pixel Shape::getcolor()
{
    return color;
}
Shape::Shape()
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
        size.resize(3);
        for( int i=0; i < size.size() ; i++)
        {
            size[i].resize(3);
        }
        for( int i=0; i < size.size() ; i++)
        {
            for(int x=0; x< size[i].size(); x++)
            {
                size[i][x]=color2;
            }
        }
        x = (size.size()/2);
        y = (size[0].size()/2)-1;
        size[x][y] = color;
        size[x-length][y+length]= color;
        size[x][y+length]= color;
        size[x+length][y+length]= color;
    }
    Shape::Shape(int s, int l, int w, Pixel p1, Pixel p2, std::vector < std::vector < Pixel > > &s2)
    {
        sides = s;
        length = l;
        width = w;
        if ( w == 0)
        {
            width = 1;
        }
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
        recalibrate();
    }
void Shape::recalibrate()
{
        if( size.size() %2 == 0)
        {
            x = (size.size()/2);
        }
        else
        {
            x = (size.size()/2)+1;
        }
        if( size[0].size() %2 == 0)
        {
            y = (size[0].size()/2);
        }
        else
        {
            y = (size[0].size()/2)+1;
        }
        double degree = (sides-2) * 180;//find degrees in the shape
        degree /= sides;//find degrees per point
        degree /= 2;
        if( sides == 8 )//done
        {
                    x-= (length/2);
                    for(double i=0; i<=100; i++)
                    {
                        size[x-((i/100)*length)][y] = color;
                    }
                    x+=(length/2);

                    for(double i=0; i<=100; i++)
                    {
                        size[x+((i/100)*(length*std::sin(degree/2))) ][y+((i/100)*(length * std::cos(degree/2))) ] = color;
                    }
                    x+=(length*std::sin(degree/2));
                    y+=(length*std::cos(degree/2)) ;

                    for(double i=0; i<=100; i++)
                    {
                        size[x][y+((i/100)*length)] = color;
                    }
                    y+=length;

                    for(double i=0; i<=100; i++)
                    {
                        size[x-((i/100)*(length*std::sin(degree/2))) ][y+((i/100)*(length*std::cos(degree/2))) ] = color;
                    }
                    x-=(length*std::sin(degree/2));
                    y+=(length*std::cos(degree/2));

                    for(double i=0; i<=100; i++)
                    {
                        size[x-((i/100)*length)][y] = color;
                    }
                    x-=length;

                    for(double i=0; i<=100; i++)
                    {
                        size[x-((i/100)*(length*std::sin(degree/2))) ][y-((i/100)*(length*std::cos(degree/2))) ] = color;
                    }
                    x-=(length*std::sin(degree/2));
                    y-=(length*std::cos(degree/2)) ;

                    for(double i=0; i<=100; i++)
                    {
                        size[x][y-((i/100)*length)] = color;
                    }
                    y-=length;

                    for(double i=0; i<=100; i++)
                    {
                        size[x+((i/100)*(length*std::sin(degree/2))) ][y-((i/100)*(length*std::cos(degree/2))) ] = color;
                    }
                    x+=(length*std::sin(degree/2));
                    y+=(length*std::cos(degree/2));
                }
        else if ( sides == 7 )//done
        {
                    for(double i=0; i<=100; i++)
                    {
                        size[x+((i/100)*(length*std::sin(degree)))][y+(i/100)*(length+std::cos(degree))] = color;
                    }

                    x+=length*std::sin(degree);
                    y+=length*std::cos(degree);
                    for(double i=0; i<=100; i++)
                    {
                        size[x+((i/100)*(length*std::cos(180-(180-(90+degree)+(degree))))) ][y+((i/100)*((length*std::sin(180-(180-(90+degree)+(degree)))))) ] = color;
                    }
                    x+=(length*std::cos(180-(180-(90+degree)+(degree))));
                    y+=(length*std::sin(180-(180-(90+degree)+(degree)))) ;
                    for(double i=0; i<=100; i++)
                    {
                        size[x-((i/100)*((length*std::cos(180-2*degree)))) ][y+((i/100)*((length*std::sin(180-2*degree)))) ] = color;
                    }
                    x-=((length*std::cos(180-2*degree)));
                    y+=((length*std::sin(180-2*degree)));
                    for(double i=0; i<=100; i++)
                    {
                        size[x-((i/100)*length)][y] = color;
                    }
                    x-=length;
                    for(double i=0; i<=100; i++)
                    {
                        size[x-((i/100)*((length*std::cos(180-2*degree)))) ][y-((i/100)*((length*std::sin(180-2*degree)))) ] = color;
                    }
                    x-=((length*std::cos(180-2*degree)));
                    y-=((length*std::sin(180-2*degree)));
                    for(double i=0; i<=100; i++)
                    {
                        size[x+((i/100)*(length*std::cos(180-(180-(90+degree)+(degree))))) ][y-((i/100)*((length*std::sin(180-(180-(90+degree)+(degree)))))) ] = color;
                    }
                    x+=(length*std::cos(180-(180-(90+degree)+(degree))));
                    y-=(length*std::sin(180-(180-(90+degree)+(degree)))) ;
                    for(double i=0; i<=100; i++)
                    {
                        size[x+((i/100)*(length*std::sin(degree)))][y-(i/100)*(length+std::cos(degree))] = color;
                    }

                    x+=length*std::sin(degree);
                    y-=length*std::cos(degree);
                    
        }
        else if ( sides == 6 )//done
        {
                    x-=(length/2);
                    for(double i=0; i<=100; i++)
                    {
                        size[x+((i/100)*length)][y] = color;
                    }
                    x+=(length/2);
                    for(double i=0; i<=100; i++)
                    {
                        size[x+((i/100)*(length/2)) ][y+((i/100)*(length * std::sqrt(3))) ] = color;
                    }
                    x+=(length/2);
                    y+=(length * std::sqrt(3)) ;
                    for(double i=0; i<=100; i++)
                    {
                        size[x-((i/100)*(length/2)) ][y+((i/100)*(length * std::sqrt(3))) ] = color;
                    }
                    x-=(length/2);
                    y+=(length * std::sqrt(3));
                    for(double i=0; i<=100; i++)
                    {
                        size[x-((i/100)*length)][y] = color;
                    }
                    x-=length;
                    for(double i=0; i<=100; i++)
                    {
                        size[x-((i/100)*(length/2)) ][y-((i/100)*(length * std::sqrt(3))) ] = color;
                    }
                   
                    y-=(length * std::sqrt(3)) ;

                    for(double i=0; i<=100; i++)
                    {
                        size[x+((i/100)*(length/2)) ][y-((i/100)*(length * std::sqrt(3))) ] = color;
                    }
                    x+=(length/2);
                    y+=(length * std::sqrt(3)) ;
        }
        else if ( sides == 5 )//done
        {
                    for(double i=0; i<=100; i++)
                    {
                        size[x+((i/100)*std::pow(std::asin((std::pow(std::sin(length), 2)*degree)/99), 2)) ][y+((i/100)*std::pow(std::asin((std::pow(std::sin(length), 2)*degree/2)/99), 2)) ] = color;
                    }
                    x+=std::pow(std::asin((std::pow(std::sin(length), 2)*degree)/99), 2) ;
                    y+=std::pow(std::asin((std::pow(std::sin(length), 2)*degree/2)/99), 2) ;
                    for(double i=0; i<=100; i++)
                    {
                        size[x-((i/100)*(length*std::cos(180-(90+(degree+(degree/2))))))][y+((i/100)*(length*std::sin(180-(90+(degree+(degree/2))))))] = color;
                    }
                    x-=(length*std::cos(180-(90+(degree+(degree/2)))));
                    y+=(length*std::sin(180-(90+(degree+(degree/2)))));
                    for(double i=0; i<=100; i++)
                    {
                        size[x-((i/100)*length)][y] = color;
                    }
                    x-=length;
                    for(double i=0; i<=100; i++)
                    {
                        size[x-((i/100)*(length*std::cos(180-(90+(degree+(degree/2))))))][y-((i/100)*(length*std::sin(180-(90+(degree+(degree/2))))))] = color;
                    }
                    x-=(length*std::cos(180-(90+(degree+(degree/2)))));
                    y-=(length*std::sin(180-(90+(degree+(degree/2)))));
                    for(double i=0; i<=100; i++)
                    {
                        size[x+((i/100)*std::pow(std::asin((std::pow(std::sin(length), 2)*degree)/99), 2)) ][y-((i/100)*std::pow(std::asin((std::pow(std::sin(length), 2)*degree/2)/99), 2)) ] = color;
                    }
                    x+=std::pow(std::asin((std::pow(std::sin(length), 2)*degree)/99), 2) ;
                    y-=std::pow(std::asin((std::pow(std::sin(length), 2)*degree/2)/99), 2) ;
                    
        }
        else if ( sides == 4)//done
        {
                    x-=(length/2);
                    for(double i=0; i<=100; i++)
                    {
                        size[x+((i/100)*length)][y] = color;
                    }
                    x+=(.5*length);
                    for(double i=0; i<=100; i++)
                    {
                        size[x][y+((i/100)*length)] = color;
                    }
                    y+=length;
                    for(double i=0; i<=100; i++)
                    {
                        size[x-((i/100)*length)][y] = color;
                    }
                    x-=length;
                    for(double i=0; i<=100; i++)
                    {
                        size[x][y-((i/100)*length)] = color;
                    }
                    y-=(length);
        }
        else if ( sides == 3)//done
        {
                    for(double i=0; i<=100; i++)
                    {
                        size[x+((i/100)*.5*length)][y+((i/100)*((length*std::sqrt(3))/2))] = color;
                    }
                    x+=(.5*length);
                    y+=((length*std::sqrt(3))/2);
                    for(double i=0; i<=100; i++)
                    {
                        size[x-((i/100)*length)][y] = color;
                    }
                    x-=length;
                    for(double i=0; i<=100; i++)
                    {
                        size[x+((i/100)*.5*length)][y-((i/100)*((length*std::sqrt(3))/2))] = color;
                    }
                    x+=(.5*length);
                    y-=((length*std::sqrt(3))/2);
        }
}
