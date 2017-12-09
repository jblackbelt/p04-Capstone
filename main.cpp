#include "shape.h"
#include "bitmap.h"

using namespace std;

Pixel color3(string);
int number(string);

int main()
{
    
    cout<< "This program makes a normal polygon of given size of legs, # of sides (min 3, max 8), color of polygon, & color of background\n";
    int length;
    int sides;
    int width;
    Pixel color;
    Pixel color2;
    vector < vector < Pixel > > size;
    string reply;
    length=number("length");
    sides=number("side");
    color=color3("poly");
    color2=color3("back");
    //cout << "Then color of polygon\n";
    //cin >> color;
    //cout << "Finnaly background color\n";
    //cin >> color2;
    do
    {
        cout << "If you would like to edit a part type length for leg lengtn, side for # of sides,\n poly for polygon color, back background color, or if you are done type done\n";
        cin >> reply;
        if(reply == "length"|| reply == "side")
        {
            if(reply == "length")
            {
                length =number(reply);
            }
            else
            {
                sides =number(reply);
            }
        }
        if(reply == "poly" || reply == "back")
        {
            if(reply == "poly")
            {
               color = color3(reply);
            }
            else
            {
                color2 = color3(reply);
            }
        }

    }while(reply != "done" && reply != "Done");
    width = (1/100)* length;
    size.resize(3*length);
    for(int i = 0; i<size.size(); i++)
    {
        size[i].resize(3*length);
    }
    Shape pic(length,sides,width,color,color2,size);
    pic.getsize(size);
    Bitmap end;
    end.fromPixelMatrix(size);
    end.save("output.bmp");
    return 0;
}

int number(string reply)
{
    int num;
    if(reply == "length")
    {
        do
        {
            cout << "First lets start with leg length\n";
            cin >> num;
            if(num < 1)
            {
                cout << "Error invalid length need to be at least 1\n";
            }
        }while(num < 1);
    }
    else if(reply == "side")
    {
        do 
        {
            cout << "Next # of sides\n";
            cin >> num;
            if(num <= 3 && num >= 8)
            {
                cout << "Error invalid # of sides need to be between 3 and 8 sides\n";
            }
        }while(num <= 3 && num >= 8);
    }
    return num;

}

Pixel color3(string reply)
{
    Pixel end;
    end.red = 0;
    end.green = 0;
    end.blue = 0;
    do
    {
        string choice;
        if(reply == "poly")
        {
            cout << "Chose a polygon color. you can choose from red, green, blue, black, white, yellow, orange, and purple, type the color you want\n";
        }
        else if(reply == "back")
        {
            cout << "Chose a background color. you can choose from red, green, blue, black, white, yellow, orange, and purple, type the color you want\n";
        }
        cin >> choice;
        if( choice == "red" ||choice == "green" ||choice == "blue" ||choice == "black" ||choice == "white" ||choice == "yellow" ||choice =="orange" ||choice =="purple")
        {
              if( choice == "red" )
              {
                end.red = 255;
                break;
              }
              else if( choice == "green" )
              {
                end.green = 255;
                break;
              }
              else if( choice == "blue" )
              {
                end.blue = 255;
                break;
              }
              else if( choice == "black" )
              {
                break;
              }
              else if( choice == "white" )
              {
                end.red = 255;
                end.green = 255;
                end.blue = 255;
                break;
              }
              else if( choice == "yellow" )
              {
                end.red = 204;
                end.green =204;
                break;
              }
              else if( choice == "orange" )
              {
                end.red = 255;
                end.green = 128;
                break;
              }
              else if( choice == "purple" )
              {
                end.red = 153;
                end.blue = 153;
                break;
              }      
        }
        else
        {
            cout << "Error with reading text try again\n";

              
        }
    }while(true);
    return end;
}
