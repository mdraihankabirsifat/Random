// https://github.com/mdraihankabirsifat/Random
#include <iostream>
#include <stack>
using namespace std;

int main()
{

    stack<int> stack; // create stack container

    stack.push(21); // push element
    stack.push(22);
    stack.push(24);
    stack.push(25);

    int num = 0;
    stack.push(num);

    stack.pop(); // remove top element
    stack.pop();
    stack.pop();

    while (!stack.empty())
    {                               // print stack contents
        cout << stack.top() << " "; // access top element
        stack.pop();                // remove after printing
    }
}

/*
Key Notes
---------
stack is a container adaptor implementing LIFO.
push() inserts element.
pop() removes top element.
top() accesses top element.
empty() checks if stack is empty.
Default underlying container is deque.
*/