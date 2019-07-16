#include <iostream>
#include "include/list.h"

using namespace std;

int main()
{
    mylist l(10);
    mylist q(6);
    cout<<"List l is = "<<l<<endl;
    cout<<"List q is = "<<q<<endl;
    l=q;
    cout<<"l=q = "<<l<<endl;
    l=l+6+7+8+9;
    cout<<"l=l+6+7+8+9 = "<<l<<endl;
    q=l;
    cout<<"q=l = "<<q<<endl;
    q=q-6-7;
    cout<<"q=q-6-7 = "<<q<<endl;
    cout<<"l[4] = "<<l[4]<<endl;
    cout<<"q[-2] = "<<q[-2]<<endl;
    q[0]=4;
    cout<<"q[0]=4 = "<<q<<endl;
    l=q;
    cout<<"l=q = "<<l<<endl;
    if (l==q)
    {
        cout << "l is equal to q" << endl;
    }
    else
    {
        cout << "l is different from q" << endl;
    }
    q=q+4;
    cout<<"q=q+4 = "<<q<<endl;
    if (l==q)
    {
        cout << "l is equal to q" << endl;
    }
    else
    {
        cout << "l is different from q" << endl;
    }
    return 0;
}
