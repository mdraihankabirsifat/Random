#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int val;
    Node* next;
    Node(){
        this->val = 0;
        this->next = nullptr;
    }
    Node(int val){
        this->val = val;
        this->next = nullptr;
    }
};

class Queue{
    public:
    Node* front, *rear;
    Queue(){
        front = rear = nullptr;
    }
    bool is_empty(){
        return front == nullptr;
    }
    void enqueue(int data){
        Node* temp = new Node(data);
        if(front == nullptr){ // empty queue
            front = rear = temp;
        }else{
            rear->next = temp;
            rear = temp;
        }
    }
    int dequeue(){
        if(is_empty()){
            throw runtime_error("The queue is empty");
        }
        int ans = front->val;
        Node* temp = front->next;
        delete front;
        front = temp;
        if(front == nullptr)    rear = nullptr;
        return ans;
    }
    int get_front(){
        if(is_empty()){
            throw runtime_error("The queue is empty");
        }
        int ans = front->val;
        return ans;
    }
};
