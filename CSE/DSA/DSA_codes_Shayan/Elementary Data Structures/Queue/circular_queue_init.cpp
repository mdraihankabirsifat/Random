#include<bits/stdc++.h>
using namespace std;

// rear = front = -1 -> empty
// (rear + 1) % maxSize = front;
// rear = front && front != -1 -> one element

class Queue{
public:
    int maxSize;
    int* arr;
    int rear, front;

    Queue(int size = 100){
        maxSize = size;
        arr = new int[maxSize];
        rear = front = -1;
    }

    ~Queue(){
        delete[] arr;
    }

    bool is_full(){
        return (rear + 1) % maxSize == front;
    }

    bool is_empty(){
        return front == -1;
    }

    void enqueue(int data){
        if (is_full()){
            throw runtime_error("Queue overflow: cannot enqueue");
        }
        if (is_empty()){
            front = rear = 0;
            arr[rear] = data;
            return;
        }
        rear = (rear + 1) % maxSize;
        arr[rear] = data;
    }

    int dequeue(){
        if (is_empty()){
            throw runtime_error("Queue underflow: cannot dequeue");
        }
        int ans = arr[front];
        if (front == rear){
            front = rear = -1;
        } else {
            front = (front + 1) % maxSize;
        }
        return ans;
    }

    int get_front(){
        if (is_empty()){
            throw runtime_error("Queue is empty: cannot get front");
        }
        return arr[front];
    }
};


