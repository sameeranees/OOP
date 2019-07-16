#include "Date.h"
#include <iostream>
#include <stdlib.h>

Date::Date()
{
    //generate date, the first day of first month of year 2017
    Day = 1;
    Month = 1;
    Year = 2017;
}

Date::Show()
{
    //display date in beautiful way
    cout << "************************* \nTodays Date: " << Day << "/" << Month << "/" << Year << "\n*************************" << endl;
}

Date::Add()
{
    //add day int to increase date by one
    Day++;
}
