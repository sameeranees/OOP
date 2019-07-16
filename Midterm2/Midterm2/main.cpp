#include <iostream>
#include "LinkedList.h"
using namespace std;

int main()
{
    LinkedList lst;
    lst.Push(5);
    lst.Push(10);
    lst.Push(7);
    lst.Pop();
    lst--;
    lst.Show();
    return 0;
}
