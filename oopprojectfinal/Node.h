#ifndef NODE_H_INCLUDED
#define NODE_H_INCLUDED
#include "GameObject.h"

struct Node
{
    GameObject* gameobject;
    Node* next;
    Node* prev;
};


#endif // NODE_H_INCLUDED
