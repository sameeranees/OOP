#include <iostream>
#include <stdio.h>
#include <fstream>
#include <unistd.h>
#include <ctype.h>
#include <string.h>
#include "Person.h"
#include "ColdDrink.h"
#include "Room.h"
#include "Date.h"
#include "Time.h"
#include <time.h>
#include <stdlib.h>

using namespace std;

string ToUpperCase(string& text);
int SearchRoom();
void All();
int SearchFloor();

int main()
{
    //intro to the system through cout
    cout << "-----------------------------------\nPEARL CONTINENTAL HOTEL RAWALPINDI\n     HOTEL MANAGEMENT SYSTEM\n-----------------------------------\nType Room to search by room number. \nType Floor to search by floor number. \nType All for report on all rooms. \n";
    cout << "Type Exit to close the program. \n";
    string choice; //to ask user what it he wants floor/room/all data or exit
    cin >> choice; //take user input
    ToUpperCase(choice); //uppercase user's choice to standardize it
    if (choice != "ALL" && choice != "ROOM" && choice != "FLOOR" && choice != "EXIT")
    {
        do
        //if user input was none of all/room/floor/exit, ask for correct input again until correct input is given
        {
            cout << "The input was invalid. \nType Room to search by room number. \nType Floor to search by floor number. \nType All for report on all rooms. \n";
            cin >> choice;
            ToUpperCase(choice);
        } while(choice != "ALL" && choice != "ROOM" && choice != "FLOOR" && choice != "EXIT");
    }
    if (choice == "ALL")
    {
        All(); //if user wants report of all seven days of all rooms
    }
    if (choice == "ROOM")
    {
        SearchRoom(); //if user wants details of a particular room
    }
    if (choice == "FLOOR")
    {
        SearchFloor(); //if user wants details of all rooms on a particular floor
    }
    if (choice == "EXIT")
    {
        return 0; //to exit program
    }
}


void All()
{
    srand(time(NULL)); //change seed of random number generator
    //since freopen does not allow us to cout through console, tell user beforehand that report has been saved
    cout << "Report has been saved to Report.txt file successfully! " << endl;
    freopen("Report.txt", "w", stdout); //store all cout data to report.txt
    Date today; //call date constructor, call date today
    Time present; //call time constructor, call time present
    Room* rooms; //make Room pointer rooms
    rooms = NULL; //assign NULL values to rooms
    rooms = new Room[30]; //make Room array of size 30, call it rooms
    int line = 1;
    string filedata[500]; //string array to store booking/customer data that hotel will provide
    filedata[0] = "Garbage string ~ Ignore"; //ignore first string of filedata, we iterate from 1st index
    string str;
    ifstream myfile("Bookings.txt"); //read from file Bookings.txt
    if (myfile.is_open())
    {
        while (getline(myfile, str))
        {
            filedata[line] = str;
            line++; //increment line, so each line from Bookings.txt is stored to the next filedata index
        }
        myfile.close();
    }
    int i = 1;
    int newcount = 0;
    int counter = 0;
    for(int z = 0; z < 7; z++)
    {
        //this loop runs 7 times, like the 7 days of the week
        today.Show(); //show the date today
        counter = newcount; //change counter to match newcount's value
        cout << "Day: " << z + 1 << endl;
        int customers;
        customers = rand() % 4 + 1; //how many customers (customer == different groups of people) enter on a particular day
        cout << "Rooms booked today: " << customers << endl; //show how many rooms were booked
        while (newcount < customers + counter) //to only show book rooms to the number of customers today and then onto the next day
        {
            if (strlen(filedata[i].c_str()) < 2) //since no. of people will always have a strlen < 2
            {
                cout << endl;
                rooms[newcount].CheckIn(atoi(filedata[i].c_str())); //check in certain number of people into rooms[newcount]
                for (int n = 0; n < 30; n++) //to iterate through 30 rooms' array
                {
                    if (newcount != n) //make sure room that is being assigned is not already occupied
                    {
                        while(rooms[newcount].roomchecker == rooms[n].roomchecker)
                        {
                            rooms[newcount].booked = false;
                            rooms[newcount].CheckIn(atoi(filedata[i].c_str()));
                        }
                    }
                }
                rooms[newcount].EnterDetails(i, atoi(filedata[i].c_str()), filedata); //enter details to room
                newcount++; //increment newcount so it reaches number of customers
                cout << endl;
            }
            i++; //increment i to iterate to next index of filedata array
        }
        for (int j = 0; j < 30; j++) //iterate through 30 rooms
        {
            if (rooms[j].booked == true) //if room is booked
            {
                cout << endl;
                rooms[j].Show(); //show room details
                int colddrinkIndex = rand() % 10 + 1; //generate random no. of colddrinks used
                rooms[j].drinks.Use(colddrinkIndex); //run colddrinks using mechanism
                cout << endl;
            }
        }
        for(int x = 0; x < 30; x++) //iterate through 30 rooms
        {
            if (rooms[x].booked == true) //if room is booked
            {
                rooms[x].days--; //subtract days i.e no. of days guest will stay
                if(rooms[x].days == 0) //if that no. is 0
                {
                    rooms[x].CheckOut(); //let the customer check out
                }
            }
        }
        today.Add(); //add one day to today's date
    }
    rooms = NULL; //set rooms pointer to NULL
    delete rooms; //delete rooms array
    fclose(stdout);
}




int SearchFloor()
{
    cout << "Type floor number: " << endl;
    int flnum;
    cin >> flnum; //ask user which floor no. data they want
    if (flnum <= 0 || flnum > 3) //if invalid floor number given
    {
        //keep running loop till correct floor number is given
        do
        {
            cout << "This floor does not exist. Type valid floor number 1,2 or 3. \nType 0 to exit program. \n";
            cin >> flnum;
            if (flnum == 0) //let user exit, if floor number given is 0
            {
                return 0;
            }
        } while(flnum == 0 || flnum > 3);
    }
    srand(time(NULL));
    //tell user beforehand report is generated since freopen redirects cout to file
    cout << "Report has been saved to floorsshow.txt file successfully! " << endl;
    freopen("floorsshow.txt","w",stdout);
    Date today; //make Date, call it today
    Room* rooms; //make Room pointer to rooms
    rooms = NULL; //set rooms to NULL
    rooms = new Room[30]; //make 30 Room array called rooms
    int line = 1;
    string filedata[500]; //make string array filedata which contains booking details that hotel provides
    filedata[0] = "Garbage string ~ Ignore"; //ignore first filedata string
    string str;
    ifstream myfile("Bookings.txt");
    //copy Bookings.txt data to filedata array
    if (myfile.is_open())
    {
        while (getline(myfile, str))
        {
            filedata[line] = str;
            line++;
        }
        myfile.close();
    }
    int i = 1;
    int newcount = 0;
    int counter = 0;
    for(int z = 0; z < 7; z++)
    {
        //iterate through 7 days of week
        today.Show(); //show today's date
        counter = newcount;
        cout << "Day: " << z + 1; //show day today
        int customers;
        customers = rand() % 4 + 1; //generate groups of people who enter hotel today
        while (newcount < customers + counter) //to make sure today's entries don't surpass no. of customers that came in
        {
            if (strlen(filedata[i].c_str()) < 2) //since no. of people who came will have strlen < 2
            {
                rooms[newcount].CheckIn(atoi(filedata[i].c_str())); //check in that number of people into room
                for (int n = 0; n < 30; n++)
                {
                    if (newcount != n) //make sure room that is being assigned is not already occupied
                    {
                        while(rooms[newcount].roomchecker == rooms[n].roomchecker)
                        {
                            rooms[newcount].booked = false;
                            rooms[newcount].CheckIn(atoi(filedata[i].c_str()));
                        }
                    }
                }
                rooms[newcount].EnterDetails(i, atoi(filedata[i].c_str()), filedata); //enter details of customers into room
                newcount++; //increment newcount
                cout << endl;
            }
            i++; //move onto next index of filedata array
        }
        cout << "Room details for floor number " << flnum << "\nNote: If no details appear, assume floor was not occupied on that day\n\n";
        for (int foo = 0; foo < 30; foo++) //throughout 30 rooms
        {
            if(rooms[foo].booked == true) //if room is booked
            {
                rooms[foo].floorshow(flnum); //run function on that room
                cout << endl;
            }
        }
        today.Add(); //add to todays date
    }
    rooms = NULL; //set rooms to NULL
    delete rooms; //delete rooms
    fclose(stdout);
    return 0;
}



int SearchRoom()
{
    cout << "Type room number: " << endl;
    int rmnum;
    cin >> rmnum; //take room number from user
    //if room number is invalid, keep asking until it is valid
    if ((rmnum < 101 || rmnum > 110) && (rmnum < 201 || rmnum > 210) && (rmnum < 301 || rmnum > 310))
    {
        do
        {
            cout << "The room number does not exist. \nType valid room number from 101-110, 201-210 and 301-310. \nType 0 to exit program. \n";
            cin >> rmnum;
            if (rmnum == 0)
            {
                return 0;
            }
        } while((rmnum < 101 || rmnum > 110) && (rmnum < 201 || rmnum > 210) && (rmnum < 301 || rmnum > 310));
    }
    srand(time(NULL));
    //tell user report is made, since freopen redirects outputs to textfile
    cout << "Report has been saved to roomsshow.txt file successfully! " << endl;
    freopen("roomsshow.txt","w",stdout);
    Date today; //make Date, set it to today
    Room* rooms; //make Room pointer rooms
    rooms = NULL; //set rooms to NULL
    rooms = new Room[30]; //make rooms array of 30 Room
    int line = 1;
    string filedata[500]; //make string array filedata, which will store hotel info on customer details
    filedata[0] = "Garbage string ~ Ignore"; //ignore first string in filedata
    string str;
    ifstream myfile("Bookings.txt");
    //take data from Bookings.txt and copy onto string array filedata
    if (myfile.is_open())
    {
        while (getline(myfile, str))
        {
            filedata[line] = str;
            line++;
        }
        myfile.close();
    }
    int i = 1;
    int newcount = 0;
    int counter = 0;
    for(int z = 0; z < 7; z++)
    //iterate through 7 days of week
    {
        today.Show(); //show today's date
        counter = newcount;
        cout << "Day: " << z + 1; //show day today
        int customers;
        customers = rand() % 4 + 1; //customers (i.e different groups of people) that come in today
        while (newcount < customers + counter) //only book rooms equal to number of customers that came in today
        {
            if (strlen(filedata[i].c_str()) < 2) //since people coming in will have strlen < 2
            {
                rooms[newcount].CheckIn(atoi(filedata[i].c_str())); //check in those no. of people into room
                for (int n = 0; n < 30; n++)
                {
                    if (newcount != n) //make sure room that is being assigned is not already occupied
                    {
                        while(rooms[newcount].roomchecker == rooms[n].roomchecker)
                        {
                            rooms[newcount].booked = false;
                            rooms[newcount].CheckIn(atoi(filedata[i].c_str()));
                        }
                    }
                }
                rooms[newcount].EnterDetails(i, atoi(filedata[i].c_str()), filedata); //enter details of customer(s)
                newcount++;
                cout << endl;
            }
            i++; //increment onto next index of filedata array
        }
        cout << endl << "Room details for room number " << rmnum << "\nIf no details appear, assume room was not occupied\n";
        for (int foo = 0; foo < 30; foo++)
        //iterate through 30 days
        {
            if(rooms[foo].booked == true)
            //if room is booked, run roomshow()
            {
                rooms[foo].roomshow(rmnum);
                cout << endl;
            }
        }
        today.Add(); //add to today's date
    }
    rooms = NULL; //set rooms to NULL
    delete rooms; //delete rooms
    fclose(stdout);
    return 0;
}
string ToUpperCase(string& text)
{
    //change text to Uppercase by iterating through each of its character and using toupper on every char
    for(int i = 0, j = strlen(text.c_str()); i < j; i++) //run for loop, from start of text till end
    {
        text[i] = toupper(text[i]); //for each char, convert it to its upper version with toupper function
    }
    return text; //return text back to main
}
