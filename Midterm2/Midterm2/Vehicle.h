#ifndef VEHICLE_H_INCLUDED
#define VEHICLE_H_INCLUDED
#include "Engine.h"
class Vehicle
{
private:
    int fuelcapacity;
    int passengers;
    Engine engine;
public:
    int FuelConsumption();
    void Move();
    void Stop();
};


#endif // VEHICLE_H_INCLUDED
