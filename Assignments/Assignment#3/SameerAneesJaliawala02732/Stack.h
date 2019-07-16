#pragma once
#include "Node.h"
#include "SDL.h"
class Stack
{
private:
    Node* head;
public:
    Stack();
    ~Stack();
    void Push(Shape*);
    Shape* Pop();
    void Draw(SDL_Renderer*);
    void Clear();
    int Counter();
    bool StackCheck();
    void Down();
    void Up();
    void Drawwhole(SDL_Renderer*);
    void dumpStack();
};
