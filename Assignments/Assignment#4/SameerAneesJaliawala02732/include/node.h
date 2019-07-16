#ifndef NODE_H_INCLUDED
#define NODE_H_INCLUDED
#include <iostream>

struct node { // node of list
    int val;
    node* next;
    node *prev;
    node(){val=0;next=NULL;}// constructor
};


#endif // NODE_H_INCLUDED
