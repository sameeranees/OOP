#include <iostream>
#pragma once

using namespace std;
class Point{
private:
    int x=0;
    int y=0;
public:
    Point();
    Point(int,int);
    void Add(int,int);
    void Add(Point&);
    void Add(Point*);
    void Show();
};
