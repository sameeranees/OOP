#include <iostream>
#include "LinkedList.h"
using namespace std;
LinkedList::LinkedList()
{
    head=NULL;
}
void LinkedList::Push(int value)
{
    if (head==NULL)
    {
        head=new Node;
        head->data=value;
        head->next=NULL;
        head->prev=NULL;
        lastvalue=head;
    }
    else
    {
        Node*temp=head;
        head=new Node;
        head->data=value;
        head->next=temp;
        head->prev=NULL;
        lastvalue->next=head;
    }
}
int LinkedList::Pop()
{
    int value=-1;
    Node*temp=head;
    Node *s=head;
    while(head->next!=s)
    {
        head=head->next;
        head->prev=temp;
        temp=temp->next;
    }
    value=head->data;
    head->data=-1;
    head=head->prev;
    while(head->prev!=NULL)
    {
        head=head->prev;
    }
    return value;
}
void LinkedList::Show()
{
    Node*temp=head;
    Node*s=head;
    while(temp->data!=-1)
    {
        cout<<temp->data<<",";
        temp=temp->next;
    }
}
LinkedList::~LinkedList()
{
    while(head!=NULL)
    {
        Pop();
    }
}
void LinkedList::operator--(int value)
{
    Node*temp=head;
    if (head!=NULL)
    {
        head=head->next;
    }
}
