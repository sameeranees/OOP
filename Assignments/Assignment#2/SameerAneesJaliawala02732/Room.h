#pragma once
#include "Person.h"//includes person object
#include "ColdDrink.h"//includes coldrink object
#include <iostream>

class Room
{
private:
    // following variables can only be used in room.cpp and not anywhere else in the other files
    int charges;
    int floor;
    int* roomNumber;
    int* phoneNumber;
    int maxPeople;
    Person* persons;
    int quantity;
    bool called;
public://following variables and functions can be used anywhere else in the other files as long as it is included
    int roomchecker;
    ColdDrink drinks;
    bool booked;
    int days;
    Room();
    void Show();
    void CheckIn(int);
    void CheckOut();
    void EnterDetails(unsigned int, int, string[]);
    void floorshow(int);
    void roomshow(int);
};
