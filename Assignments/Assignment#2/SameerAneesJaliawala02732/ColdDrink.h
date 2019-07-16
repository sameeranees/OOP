#pragma once
#include <iostream>

using namespace std;

class ColdDrink
{
private:
    // following variables can only be used in colddrink.cpp and not anywhere else in the other files
    string* Company;
    int* Capacity;
    int count;
public://following variables and functions can be used anywhere else in the other files as long as it is included
    ColdDrink();
    void Use(int);
};
