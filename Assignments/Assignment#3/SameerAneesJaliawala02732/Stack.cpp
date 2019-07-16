#include<iostream>
#include "Stack.h"
#include "Shape.h"
#include "Node.h"
#include "time.h"

using namespace std;

Stack::Stack()
{
    head = NULL; //initialize stack
}

Stack::~Stack()
{
    while(head!=NULL)
    {
        Pop(); //destruct stack by popping each node one by one
    }
    head=NULL;
    delete head;
}
void Stack::Push(Shape* val)
{
    if (head == NULL) //basically pushing shape into an empty stack
    {
        head = new Node;
        head->shape=val; //the new Node becomes the head, it's shape is now val
        head->prev=NULL;
        head->next = NULL; //the next and prev are now NULL since it is first node
    }
    else
    {
        Node* temp = head; //Node pointer temp points to head
        head = new Node;
        head->shape = val; //head becomes a new node that stores val in shape
        head->prev=NULL; //prev node of head is NULL since head is top (prev here means above basically)
        head->next = temp; //the node next to head is the previous head, which is accessible through temp
    }
}

Shape* Stack::Pop()
{
    Shape* val = NULL;
    if (head == NULL)
    {
        cout << "HEAD IS NULL!" << endl;
    }
    if (head != NULL)
    {
        val = head -> shape; //makes val equal to shape of the head
        Node* temp = head;
        head = temp->next; //head is basically transferred to it's next node, by using an auxiliary node temp
        temp=NULL; //make temp NULL
        delete temp;
    }
    return val; //the shape in head is thus returned
}

void Stack::Draw(SDL_Renderer* gRenderer)
{
    if(head!=NULL)
    {
        //in next step, use previously defined colors of shape
        SDL_SetRenderDrawColor(gRenderer, head->shape->getcol1(), head->shape->getcol2(), head->shape->getcol3(), head->shape->getcol4());
        head->shape->Draw(gRenderer); //draw the shape stored in head
    }
    if (head==NULL)
    {
    }

}

void Stack::Clear()
{
    while (head != NULL)
    {
        Pop(); //clear entire stack by popping each node one by one
    }
}

int Stack::Counter()
{
    //a utility function to count number of shapes in stack
    int i = 0;
    Node* temp = head; //temp points to head
    while (temp != NULL)
    {
        i++; //increment i until temp is NULL
        temp = temp->next; //move temp onto next node
    }
    return i; //return number of shapes in stack
}

bool Stack::StackCheck()
{
    if (head == NULL)
    {
        return true; //if stack is NULL, return true
    }
    return false; //if stack is not NULL, return false
}

void Stack::Down()
{
    if (head -> next != NULL) //check if next node is not null, since every step we move onto the next node of current node
    {
        Node* temp = head; //temp points at head
        head = temp -> next; //head now points at its next node
        head -> next = temp->next->next; //the node next to head points at node next to the next node of temp (which is original head)
        head->prev = temp; //node previous to head is now temp
        cout<<"DOWN"<<endl;
        temp=NULL;
        delete temp;
    }
}

void Stack::Up()
{
    if (head -> prev != NULL)//if the previous value before head pointer is not NULL
    {
        cout << "UP" << endl;//prints UP
        Node* temp = head;// temp points at head
        head = temp -> prev;//head now points at its previous node
        head -> prev = temp -> prev -> prev;//the node previous to head points at node previous to the previous node of temp (which is original head)
        head -> next = temp;//node next to head is now temp
        temp=NULL;
        delete temp;
    }
}

void Stack::Drawwhole(SDL_Renderer* gRenderer)
{
    Node* temp = head;
    while (temp!= NULL) //draw entire stck one by one
    {
        SDL_SetRenderDrawColor(gRenderer, temp->shape->getcol1(), temp->shape->getcol2(), temp->shape->getcol3(), temp->shape->getcol4());
        temp->shape->Draw(gRenderer);
        temp=temp->next;
    }
}
