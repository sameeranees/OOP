#ifndef TRUCK_H_INCLUDED
#define TRUCK_H_INCLUDED
#include "Vehicle.h"
class Truck::public Vehicle
{
private:
    int loadcapacity;
public:
    void load();
    void offload();
};


#endif // TRUCK_H_INCLUDED
