#include <iostream>
#include"Point.h"
using namespace std;
Point::Point()
{
    x=0;
    y=0;
}
Point::Point(int x1,int x2)
{
    x=x1;
    y=x2;
}
void Point::Add(int x1,int x2)
{
    int newx=0;
    int newy=0;
    newx=x+x1;
    newy=y+x2;
    x=newx;
    y=newy;
}
void Point::Add(Point &point)
{
    x=x+(point.x);
    y=y+(point.y);
}
void Point::Add(Point *point)
{
    x=x+(point->x);
    y=y+(point->y);
}
void Point::Show()
{
    cout<<"x is "<<x<<endl;
    cout<<"y is "<<y<<endl;
}
