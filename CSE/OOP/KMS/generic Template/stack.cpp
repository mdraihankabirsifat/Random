#include <iostream>
//#include<bits/stdc++.h>
using namespace std;
const int SIZE = 10;
template <class StackType>
class stack
{
    StackType stck[SIZE];
    int tos;

public:
    stack()
    {
        tos = 0;
    }
    void push(StackType ob)
    {
        if (tos == SIZE)
        {
            cout << "Stack is full\n";
            return;
        }
        stck[tos++] = ob;
    }

    StackType pop()
    {
        if (tos == 0)
        {
            cout << "Stack is empty\n";
            return 0;
        }
        return stck[--tos];
    }
};

int main()
{
    stack<int> s;
    s.push(10.5);
    s.push(20);

    stack<float> s1;
    s1.push(10.3);
    s1.push(20.6);

    cout << s.pop() << endl;
    cout << s.pop() << endl;

    cout << s1.pop() << endl;
    cout << s1.pop() << endl;

    return 0;
}