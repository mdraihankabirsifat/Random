#include<bits/stdc++.h>
using namespace std;
int main()
{
    //last in; first out
    stack<int>s;
    s.push(1);
    s.push(2);
    s.push(3);
    cout<<s.top()<<"\n";
    s.pop();
    cout<<s.top()<<"\n";
    return 0;
}