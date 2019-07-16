#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <ctype.h>
#include <cstdlib>
#include <windows.h>

using namespace std;

void TimeDelay(int delay = 3);  //This function should delay the execution to 3 second default, 0 sec min and 10 sec max
string ToUpperCase(string&);    //Converts a string to UpperCase. Also returns the string if required.
void read(int*);               //Reads a file and gets a pointer to the variable in main that holds the count of letters read
int edit();                    //Creates and writes a new file

int main()
{
    int count = 0;  //variable to keep count of # of characters read so far
    string command; //string that stores the user input i.e. read/edit/exit
    bool loopRunning = true; //we need the editor to keep running until we tell it to stop. the bool loopRunning is responsible for that.
    while (loopRunning)
    {
        system("CLS"); //clears the screen. once done editing/reading, it gives the user a fresh screen. for aesthetic purpose.
        cout << "Total characters read so far: " << count << endl << endl;
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl << "  WELCOME TO TEXT EDITOR!" << endl << "~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        cout << "\nType 'edit' to edit a text file" << endl;
        cout << "Type 'read' to read a text file" << endl;
        cout << "Type 'exit' to exit program" << endl << endl;
        cout << "Choose what you want to do: ";
        cin >> command; //this lets command store the user input
        ToUpperCase(command); //the user input will be upper-cased, so user has freedom to type however he chooses too
        while (command != "EDIT" && command != "READ" && command != "EXIT") //if upper-cased user input is none of our designated commands, ask again
        {
            cout << "Input is invalid. Enter valid input: ";
            cin >> command;
            ToUpperCase(command);
        }
        if (command == "EDIT")
        {
            edit(); //if command is edit, proceed to edit
        }
        else if (command == "READ")
        {
            read(&count); //if command is read, proceed reading with the address of the count as argument
        }
        else //if command is exit
        {
            TimeDelay(); //take 3 second pause
            loopRunning = false; //make bool loopRunning false, which makes the while loop false, and exits
        }
    }
    return 0;
}



void TimeDelay(int delay)
{
    cout << "Please wait. "; //asks user to wait before countdown
    while (delay != 0) //for aesthetic purpose, function will countdown till 1.
    {
        cout << delay << ". "; //will output delay one by one. if input is none, it goes "3,2,1." same for any other input.
        Sleep(1000);
        delay--;
    }
}


string ToUpperCase(string& text)
{
    for(int i = 0, j = strlen(text.c_str()); i < j; i++) //run for loop, from start of text till end
    {
        text[i] = toupper(text[i]); //for each char, convert it to its upper version with toupper function
    }
    return text; //return text back to main
}

void read (int *count)
{
    int line = 0; //current line
    int line_num = 24; //the line at which user should be prompted to continue or not
    string choice;
    string filename; //the filename which is to be read
    string str; //string that reads file line by line
    ifstream readfile; //ifstream - to read file
    cout << "Enter name of the file to read: " << endl;
    cin >> filename; //asks for name of file to be read.
    readfile.open(filename.c_str()); //opens the file
    while(!readfile) // if file does not exit, it will ask to enter the filename again and will open it.
    {
        cout << "File does not exist. Enter correct filename: ";
        cin >> filename;
        readfile.open(filename.c_str());
    }
    while(getline(readfile, str)) //reads line from file and assigns it to str
    {
        if (line >= 1) //necessary loop since getline skips first loop, will only print ">" if line is 1 or more
        {
            cout << line << ">" ; //prints line number
            cout << str << endl; //prints the contents of the line/str
            if(line % line_num == 0) //when line number reaches 24
            {
                cout << "***Do you want to continue? Type Yes to proceed or anything else to return to Main Menu.***" << endl; //will ask the user to continue
                cin >> choice;//takes user input
                ToUpperCase(choice);
                if(choice == "YES")//if yes, it continues reading
                {
                }
                else//if no it will stop reading
                {
                    *count = *count + str.length();//increments count and and gets a pointer to the variable in main that holds the count of letters read
                    break;//breaks the loop
                }
            }
        }
        *count = *count + str.length(); //increments count and and gets a pointer to the variable in main that holds the count of letters read
        line++; //increments line
    }
    if(line==1)//as incrementation is ahead of the current line we use 1(it will only work when there is no data in file)
    {
        cout<<"File is empty"<<endl;
    }
    cout << endl << "*****Reading Done!*****" << endl;
    system("PAUSE"); //will ask the user to continue
    TimeDelay(); //time delay of 3 seconds
    readfile.close(); //closes the file.
}

int edit()
{
    int line = 0; //to print "line>" before every user input
    ofstream writefile; //ofstream - to write file
    string str; //string that becomes the user input
    string filename; //file to be edited
    cout << "Enter name of the file to edit: "<<endl;
    cin >> filename;
    cout << "Note: Once done editing, enter into a new line and press either '/' or CTRL+X to stop the process and save file." << endl;
    writefile.open(filename.c_str()); //open file
    while(writefile.is_open()) //while file is open
    {
        if (line != 0) //necessary loop since getline skips first loop, will only print ">" if line is 1 or more
        {
            cout << line << ">" ; //prints line number
        }
        getline(cin, str); //get user input and make it string
        if (str == "" || str == "/")
        {
            break; //if user input is one of above, exit the editing process, back to main
        }
        writefile << str.c_str() << endl; //write user input str to file in writefile
        line++; //increment line
    }
    writefile.close(); // close file
    cout << endl << "*****Editing Done!*****" << endl;
    TimeDelay(); //3 second delay
    return 0;
}

