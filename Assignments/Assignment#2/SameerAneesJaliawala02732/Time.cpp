#include "Time.h"
#include "time.h"
#include "stdlib.h"
#include <iostream>

using namespace std;

Time::Show()
{
    seconds = rand() % 61; //make random seconds less than 60
    minutes = rand() % 61; //make random minutes less than 60
    hours = rand() % 24; //make random hours less than 24
    cout << hours << ":" << minutes << ":" << seconds << endl; //output time
}
