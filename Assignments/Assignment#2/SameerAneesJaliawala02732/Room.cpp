#include <iostream>
#include <time.h>
#include <stdlib.h>
#include "Room.h"//includes object room header
#include "Person.h"//includes person object
#include "ColdDrink.h"//includes coldrink object
#include "Time.h"//includes time object
#include <time.h>

using namespace std;

Room::Room()
{
    roomchecker = 0;// variable initialized. It is used to make sure the same room is not allocated to another guest while it is already booked
    called = false;// bool variable initialized. to make sure printing and calling of function doesnt repeat. used in roomshow and floorshow.
    quantity = 0;// no of guests(copy)
    booked = false;// initializes bool variable to see if room is booked or not.
    charges = 0;// initializes charges of the room
    floor = 0;// initializes floor of hotel
    roomNumber = NULL;// initializes roomnumber
    phoneNumber = NULL;//initializes phonenumber
    maxPeople = 0;//occupancy of room
    days = 0;// no of days the guest is going to stay
    persons = NULL;// initializes persons which is an object.
}

void Room::CheckIn(int people)// checks in the no of people coming in
{
    quantity = people;// quantity is now equal to no of people coming in
    this -> roomNumber = new int[3];// roomnumber points to an int array of size 3
    this -> phoneNumber = new int[4];// phonenumber points to an int array of size 3
    days = rand() % 7 + 2;// random no of days the guest is in hotel
    bool run = true;// assigns local variable run
    while (run == true)// will run until run=false
    {
        maxPeople = rand() % 4 + 2;// random no of guests staying in hotel
        floor = rand() % 3 + 1;// random floor assigned
        roomNumber[0] = floor;// first element of room is floor
        int j = rand() % 10 + 1;// local variable assigned random int between 1 and 10. Used to assign roomnumber
        if (j == 10)// when j=10
        {
            roomNumber[1] = 1;// if j=10 then room number will be floornumber as first element and the nest int will be 10.
            roomNumber[2] = 0;
        }
        else
        {
            //if j<10 then room number will be floornumber as first element and the nest int will be 0 and then j.
            roomNumber[1] = 0;
            roomNumber[2] = j;
        }
        //assigning phonenumber according to roomnumber
        phoneNumber[0] = 0;
        phoneNumber[1] = roomNumber[0];
        phoneNumber[2] = roomNumber[1];
        phoneNumber[3] = roomNumber[2];

        if (people < maxPeople && booked == false && people<2)// if the number of guests is 1 and room is not booked.
        {
            for (int i = 0; i < 3; i++)// roomchecker is assigned the roomnumber
            {
                 roomchecker=roomchecker+roomNumber[i];
            }
            booked = true;// room will be booked if the if statement works
            charges = days * 100*2;// charges will be assigned according to no of days the customer is staying and the occupancy of the room
            run = false;// will end the while loop at the end of this loop
        }
        if (people == maxPeople && booked == false && people>=2)// if the number of guests is more than 1 and room is not booked.
        {
            for (int i = 0; i < 3; i++)// roomchecker is assigned the roomnumber
            {
                 roomchecker=roomchecker+roomNumber[i];
            }
            booked = true;// room will be booked if the if statement works
            charges = days * 100*people;// charges will be assigned according to no of days the customer is staying and the occupancy of the room
            run = false;// will end the while loop at the end of this loop
        }
    }
}

void Room::EnterDetails(unsigned int filedataIndex, int people, string filedata[])// enters the details of the guests
{
    this -> persons = new Person[people];// person points to a new object array Person of size people
    int j = 0;//local variable initialized
    filedataIndex++;//increments filedataindex
    while (j < people)// assigns data of people from array of data(taken from main) and assigns it to an object array of persons
    {
        persons[j].Name = filedata[filedataIndex];//assigns names
        filedataIndex++;//increments filedataindex
        persons[j].DOB = filedata[filedataIndex];//assigns date of birth
        filedataIndex++;//increments filedataindex
        persons[j].CNIC = filedata[filedataIndex];//assigns cnic
        filedataIndex++;//increments filedataindex
        j++;//increments j
    }
}
void Room::CheckOut()// wiil checkout people of a particular room
{
    Time present;// present is now a time object(which is a class)
    cout << "Room Number: ";//prints roomnumber
    for (int i = 0; i < 3; i++)
    {
        cout << roomNumber[i];
    }
    cout << " checked out today at ";//shows time of checkout
    present.Show();//shows time of checkout
    booked = false;// room is now unbooked
    maxPeople = 0;// occupancy of room is now 0
    charges = 0;// charges are dropped
    for(int i = 0; i < 3; i++)// deinitializes roomnumber and phonenumber of room checked out
    {
        roomNumber[i]=0;
        phoneNumber[i]=0;
    }
    phoneNumber[4]=0;
    persons=NULL;//first it makes the following three objects= null and then deallocates memory
    phoneNumber=NULL;
    roomNumber=NULL;
    delete persons;
    delete phoneNumber;
    delete roomNumber;
}
void Room::Show()// shows the details of room
{
    Time present;// present is now a time object(which is a class)
    cout << endl;
    cout << "Time: ";
    present.Show();//shows time
    cout << "Floor Number: " << roomNumber[0] << endl;//prints details of room such as roomnumber and phonenumber
    cout << "Room Number: ";
    for (int i = 0; i < 3; i++)
    {
        cout << roomNumber[i];
    }
    cout << endl << "Phone Number: ";
    for (int i = 0; i < 4; i++)
    {
        cout << phoneNumber[i];
    }
    cout << endl << "Guests: " << quantity << endl;// prints the number of guests staying in room
    cout <<"Charges are: " << charges << endl;// prints charges of room
    cout <<"The number of days the guests are going to stay:  " << days << endl;// prints how many days the guest is to stay
    for (int i = 0; i < quantity; i++)// prints details of each person in room
    {
    cout << "Name: " << persons[i].Name << endl;
    cout << "CNIC: " << persons[i].CNIC << endl;
    cout << "Date of Birth: " << persons[i].DOB << endl;
    }
}
void Room::floorshow(int flnum)//if the staff wants the report of a particular floor then this is called
{
    if(roomNumber[0] == flnum)// if floor== flnum. Makes sure the floor the staff is asking is the same as the floor that has details.
    {
       if (called == false)//to make sure printing and calling of function doesnt repeat
       {
           called = true;// assigns called to true
           cout << "Checked In today" << endl;
           Show();// calls function call
       }
       if(days != 0)// if days left for guest is not zero then it prints the roomnumber and shows how many drinks the customer used
       {
            if(called == true)// to make sure the show function has already been called and printing is done.
            {
                cout << "Room Number: ";
                for (int i = 0; i < 3; i++)
                {
                    cout << roomNumber[i];
                }
            }
            int colddrinkIndex = rand() % 10 + 1;// the amount of drinks used per room
            drinks.Use(colddrinkIndex);// calls function that makes sure the colddrink was used and also if the fridge needs to be refilled
       }
       days--;
       if(days == 0)// if the days left for guest to stay at hotel is zero then it checksout the guests
        {
            CheckOut();
        }
    }
}
void Room::roomshow(int rmnum)//if the staff wants the report of a particular floor then this is called
{
    if (rmnum == roomchecker)// if roomnumber== rmnum. Makes sure the room the staff is asking is the same as the room that has details.
    {
        if (called == false)//to make sure printing and calling of function doesnt repeat
        {
           called = true;// assigns called to true
           cout << "Checked In today" << endl;
           Show();// calls function call
        }
        if(days != 0)// if days left for guest is not zero then it prints the roomnumber and shows how many drinks the customer used
        {
            cout << endl;
            if(called == true)// to make sure the show function has already been called and printing is done.
            {
                cout << "Room Number: ";
                for (int i = 0; i < 3; i++)
                {
                    cout << roomNumber[i];
                }
            }
            int colddrinkIndex = rand() % 10 + 1;// the amount of drinks used per room
            drinks.Use(colddrinkIndex);// calls function that makes sure the colddrink was used and also if the fridge needs to be refilled
       }
       days--;
       if(days == 0)// if the days left for guest to stay at hotel is zero then it checksout the guests
        {
            CheckOut();
        }
    }
}
