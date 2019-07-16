#include <iostream>
#include "Point.h"
using namespace std;

void AllAreas(Point point1[],Point point2[])
{
    int TriArea=0;
    int rectarea=0;
    int length=0;
    int width=0;
    for(int i=0;i<3;i++)
    {
        int x1=point1[i].x;
        int x2=point2[i].x;
        int y1=point1[i].y;
        int y2=point2[i].y;
        length=(x2)-(x1);
        width=(y2)-(y1);
        TriArea=(length*width)/2;
        rectarea=TriArea*2;
        cout<<"Area"<<i<<" is:"<<rectarea;
    }
}
int main()
{
    Point point;
    point.Show();
    Point point2(5,10);
    point2.Show();
    point2.Add(6,7);
    point2.Show();
    Point point3(8,9);
    point3.Add(&point2);
    point3.Show();
    Point *point4;
    point4=new Point(6,10);
    point3.Add(point4);
    point3.Show();
    Point point6[3]={(0,1),(2,2),(1,8)};
    Point point7[3]={(12,30),(12,10),(5,9)};
    AllAreas(point6,point7);
}

