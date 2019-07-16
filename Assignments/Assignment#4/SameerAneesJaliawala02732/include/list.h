#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED
#include <iostream>

#include "node.h"
using namespace std;
class mylist{
public:

    mylist(){start=NULL;}// constructor
    mylist(int); //overloaded constructor
    ~mylist();//distructor
    mylist( mylist&); //copy constructor
    void deletesmth(); // clears list
    void operator=( const mylist&); //operator =
    mylist& operator+(int); // operator + that adds int to list
    mylist& operator+(const mylist&);// operator + that adds another list to list
    mylist& operator-(int);// operator - that removes int to list
    int& operator[](int loc); // operator [] that returns value of index int in list
    friend ostream& operator <<(ostream&, mylist&); // friend function that returns list that can be used to cout list
    bool operator ==( mylist&); // operator that checks if list are equal
    void append(int); //function that appends int to list
    void print();// function that prints list
    int  length();// function that calculates length of list
    void remove_at(int); // function that removes value at index int
    int get_value_index(int); //function that gets index of specified value
    int& get_value_at(int); // function that gets value at specified index

private:
    node* start;// start is a node
};
ostream& operator <<(ostream&, mylist&);// function that is friend of class mylist
#endif // LIST_H_INCLUDED
