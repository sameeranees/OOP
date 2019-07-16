#include <iostream>
#include <stdlib.h>
#include "include/list.h"
using namespace std;

mylist::mylist(int sze) //overloaded constructor
{
    int sze2= 0; // initializing sze2
    start=NULL;  //initializing start
    while(sze2!=sze) // loop until sze2 is not equal to sze
    {
        if (start==NULL)// if starting pointer is null then populate it with 0
        {
            node* p = new node; //creates a node p
            if(p==NULL){cerr<<"Unable to allocate memory"<<endl; exit(0);}

            p->val =0;// assigns p as 0
            start = p;// start is now equal to p
            sze2++; // increments sze2
        }
        else
        {
            //go to list's end
            node* s = start;// creates a node s
            while (s->next) s=s->next;//go to list's end

            node* p = new node;//creates a node p
            if(p==NULL){cerr<<"Unable to allocate memory"<<endl; exit(0);}// if node is null exit constructor with return value of 0

            p->val = 0;//value of p is now 0
            s->next = p;// next pointer of s is now p
            sze2++;// increments sze2
        }
    }
}


mylist::~mylist() // distructor
{
    deletesmth(); // clears the list
    start=NULL;// start pointer is now null
}


mylist::mylist(mylist& lst) // copy contructor
{
    for (int i=0;i<lst.length();i++)// loop until it reaches end
    {
        append(lst.get_value_at(i));// appends value of list to its copy list
    }
}


void mylist::operator=(const mylist& lst)// operator =
{
    this->deletesmth();// clear the list
    node *temp=lst.start;// create new node that points to a new node
    while(temp!=NULL)// loop until temp is null
    {
        append(temp->val);// append val of temp to the list
        temp=temp->next;// temp now equal to its next pointer
    }
}

void mylist::deletesmth()// clears the list
{
    while(start!=NULL)// loop until start pointer is null
    {
        node* temp = start;// new node temp points to start
        start = temp->next; // start now points to temp next pointer
        delete temp;// deallocates temp
        temp=NULL;// temp is now null
    }
}
mylist& mylist::operator+(int data)// operator +
{
    mylist* temp= new mylist(*this);// a list created that has same elements of this list // calling the copy constructor
    temp->append(data);// appends data to temp
    return *temp;// return int
}

mylist& mylist::operator+(const mylist& toappend)// operator + that adds list
{
    mylist*lst=new mylist(*this);// a list created that has same elements of this list // calling the copy constructor
    node *temp = lst->start;// new node temp points to start of temp
    while(temp->next!=NULL)// loop until end of list
    {
        temp=temp->next;
    }
    node*temp2=toappend.start; // new node temp points to start of argument
    while(temp2!=NULL) // appends values of toappend to lst until no more values to append
    {
        lst->append(temp2->val);
        temp2=temp2->next;
    }
    return *lst;// returns lst
}


mylist& mylist::operator-(int data)// operator - that removes elements
{
    mylist*lst=new mylist(*this);// a list created that has same elements of this list // calling the copy constructor
    node *temp = lst->start;// new node temp points to start of temp
    while(lst->get_value_index(data)!=-1) // while the element data is in the list lst, it will remove the data from the index passed by function get_value_index
    {
        if (temp->val==data)
        {
            lst->remove_at(get_value_index(data)); //it will remove the data from the lst index passed by function get_value_index
        }
        temp=temp->next;
    }
    return *lst; // return updated list lst
}


int& mylist::operator[](int loc) // operator [] that returns list value specified at an index
{

    return get_value_at(loc);// calls and returns the value at the index passed.It will call function get_value_at
}


ostream& operator <<(ostream& stream, mylist& lst)// friend function operator<< that prints the list
{
    node* s = lst.start; //new node s points to start of lst
    stream<<"{";
    while(s!=NULL){ //while no more values remain,print values of list, // loop until end of list
        stream<<s->val;
        if(s->next!=NULL)
        {
            stream<<",";// if element is at the end of the list then there would be no comma
        }
        s=s->next;
    }
    stream<<"}";
    return stream;// returns stream that can be used to cout the list
}


bool mylist::operator ==( mylist& lst) // operator function that checks if values in list and size is same
{
    bool truep= true;// intializing variable of type bool
    node *temp= start; //new node temp points to start
    node * temp2= lst.start; //new node temp2 points to start of lst
    while(truep==true) // while the two lists are identical
    {
        if (length()!=lst.length()) // checks if length of both lists are same, if not then it breaks
        {
            truep=false;
            break;
        }
        int sze=length(); // initializing and assigning sze the length of list
        while(sze!=0) // while sze is not 0
        {
            if (temp->val!= temp2->val) // if the data does not match then it breaks
            {
                truep=false;
                break;
            }
            temp=temp->next; // moves to next node
            temp2=temp2->next;// moves to next node
            sze--; // increments sze
        }
        break;// breaks loop
    }
    return truep; // return if two lists are identical or not
}


void mylist::append(int val){// appends value at the end of list

    if (start==NULL) //checks if the first node is null
    {
        node* p = new node; //creates a node p
        if(p==NULL){cerr<<"Unable to allocate memory"<<endl; exit(0);} // if p is null it exits with return value 0

        p->val = val;// value of p is now val passed by function
        start = p; // start pointer is now p
    }
    else
    {
        //go to list's end
        node* s = start; //creates a node s
        while (s->next) s=s->next; //go to list's end

        node* p = new node; //creates a node p
        if(p==NULL){cerr<<"Unable to allocate memory"<<endl; exit(0);} // if p is null it exits with return value 0

        p->val = val; // value of p is now val
        s->next = p; // next pointer of s is now p
    }
}



void mylist::print() // prints all elements of list, does the same as operator function <<
{
    node* s = start;
    cout<<"{";
    int sze=length();
    while(sze!=0){
        cout<<s->val;
        if(sze!=1)
        {
            cout<<",";
        }
        s=s->next;
        sze--;
    }
    cout<<"}";
}


int mylist::length(){ // finds length of list
    int i = 0; // initialize int i to 0
    node* temp = start; //temp points to start
    while (temp != NULL) // while temp is not null
    {
        i++; //increment i until temp is NULL
        temp = temp->next; //move temp onto next node
    }
    return i;// return length i
}

void mylist::remove_at(int ind){ // removes element at index ind
        if(ind<0 || ind>=length()){ // if index is more than or equal to index or less than 0 then give error
            cerr<<"Invalid index passed  to remove_at()"<<endl;
            exit(-1);
        }

    node *behind = start;//temp points to start
    if(ind==0)// if index is 0, remove the starting element and deallocate behind
    {
        start = start->next;
        delete behind;
        behind=NULL;
    }
    else{
        //now go to the appropriate location
        node* ahead  = behind->next; //ahead points to next pointer of behind
        for (int i=1; i<ind; i++){// loop until list reaches index ind
            behind = ahead;
            ahead  = ahead->next;
        }
        behind->next = ahead->next;// then remove element and make sure next value is now handled and surely the list will behandled
        delete ahead;// deallocate ahead
        ahead=NULL;
    }
}

int mylist::get_value_index(int val){ //gets the index of value

    int index = -1; // initializes index to -1
    node *tmp = start; //temp points to start
    while(tmp){ // while temp is not null
        index++;// increment index
        if(tmp->val==val)
            break; // if value found break
        tmp = tmp->next;
    }

    if(tmp) return index; // return index where value found
    else    return -1; // if not found return -1
}

int& mylist::get_value_at(int index){ // function that gets value at the specified index

    if(index>=length()){ // if index more than or equal to length then give error
            cerr<<"Invalid index passed  to get_value_at()"<<endl;
            exit(-1);
    }
    if(index>=0)// if index is positive
    {
        node *s = start;//s points to start
        for (int i=0; i<index; i++)// loop until list reaches index
            s= s->next;

        return s->val;// return value at the index
    }
    else if(index<0) // if index is negative
    {
        node* temp= start; //temp points to start
        int j=length()+index; // initialize j to length of list + index
        for(int i=0;i<j;i++) // loopuntil list reaches index j
        {
            temp=temp->next;
        }
        return temp->val; // return value at that index
    }
    exit(-1);// exit with return value -1
}
