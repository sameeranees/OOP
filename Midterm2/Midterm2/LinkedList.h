#ifndef LINKEDLIST_H_INCLUDED
#define LINKEDLIST_H_INCLUDED
#include "Node.h"
class LinkedList
{
private:
    Node* head;
    Node*lastvalue;
public:
    LinkedList();
    ~LinkedList();
    void Push(int);
    int Pop();
    void Show();
    void operator--(int);
};


#endif // LINKEDLIST_H_INCLUDED
