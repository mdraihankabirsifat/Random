#include <iostream>
#include <queue>
using namespace std;

// Print the queue
void print_queue(queue<int> &temp)
{
    //queue<int> temp = q; // copy queue
    // 1 2 3
    while (!temp.empty())
    {
        cout << temp.front() << " " << temp.back() << '\n'; // show front and back
        temp.pop();
    }

    cout << '\n';
}

int main()
{

    queue<int> q1;

    q1.push(1);
    q1.push(2);
    q1.push(3);

    cout << "The first queue is : ";

    print_queue(q1);

    while (!q1.empty())
    {
        cout << q1.front() << " " << q1.back() << '\n'; // show front and back
        q1.pop();
    }

    return 0;
}

/*
Key Notes
---------
queue implements FIFO structure.
push() inserts element at back.
pop() removes element from front.
front() returns first element.
back() returns last element.
*/