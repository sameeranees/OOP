#pragma once
#include <iostream>

using namespace std;

class Date
{
private:
    //date will have day, month, year
    int Day;
    int Month;
    int Year;
public:
    Date(); //make a date
    Show(); //show date
    Add(); //add to date
};
