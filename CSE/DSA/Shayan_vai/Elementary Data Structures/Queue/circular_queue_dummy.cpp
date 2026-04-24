#include<bits/stdc++.h>
using namespace std;

// Dummy Node implementation
// (rear + 1) % maxSize = front -> empty
// (rear + 2) % maxSize = front -> full
// rear = front -> one element

class Queue{
    public:
    int* arr;
    int maxSize, rear, front;
    Queue(){
        maxSize = 100;
        arr = new int[maxSize];
        rear = 0, front = 1;
    }
    ~Queue(){
        delete[] arr;
    }
    bool is_full(){
        return (rear + 2) % maxSize == front;
    }
    bool is_empty(){
        return (rear  + 1) % maxSize == front;
    }
    void enqueue(int data){
        if(is_full()){
            throw runtime_error("Queue is full");
        }
        rear = (rear + 1) % maxSize;
        arr[rear] = data;
    }
    int dequeue(){
        if(is_empty()){
            throw runtime_error("Queue is empty");
        }
        int ans = arr[front];
        front = (front + 1) % maxSize;
        return ans;
    }
    int get_front(){
        if(is_empty()){
            throw runtime_error("Queue is empty");
        }
        return arr[front];
    }
};