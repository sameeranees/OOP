#ifndef CAR_H_INCLUDED
#define CAR_H_INCLUDED
#include "Vehicle.h"
class Car::public Vehicle
{
private:
    string type;
public:
    void Honk();
};


#endif // CAR_H_INCLUDED
