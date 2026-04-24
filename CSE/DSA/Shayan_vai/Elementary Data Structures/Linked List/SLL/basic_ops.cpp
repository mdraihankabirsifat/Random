#include <bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node* next;
    Node(int val){
        data = val;
        next = nullptr;
    }
};

void insert_at_head(Node*& head, int val){
    Node* temp = new Node(val);
    temp->next = head;
    head = temp;
}

void insert_at_tail(Node*& head, int val){
    Node* new_node = new Node(val);
    if(!head){
        head = new_node;
        return;
    }
    Node* temp = head;
    while(temp->next) temp = temp->next;
    temp->next = new_node;
}

void insert_at_k(Node*& head, int val, int k){
    if(k == 0){
        insert_at_head(head, val);
        return;
    }

    Node* temp = head;
    for (int i = 0; i < k - 1 && temp; i++) temp = temp->next;

    if(!temp){
        cout << "Position out of bounds\n";
        return;
    }

    Node* new_node = new Node(val);
    new_node->next = temp->next;
    temp->next = new_node;
}

Node* reverse(Node*& head){
    Node* prev = nullptr;
    Node* cur = head;
    while(cur){
        Node* store = cur->next;
        cur->next = prev;
        prev = cur;
        cur = store;
    }
    head = prev;
    return head;
}

void delete_head(Node*&head){
    if(!head)   return;
    Node* temp = head->next;
    delete head;
    head = temp;
}

void delete_tail(Node*&head){
    if(!head)   return;
    if(!head->next){
        delete head;
        head = nullptr;
        return;
    }
    Node*temp = head;
    while(temp->next->next)   temp = temp->next;
    delete temp->next;
    temp->next = nullptr;
}

void delete_at_k(Node*&head, int k){
    Node* temp = head;
    if(k == 0){
        delete_head(head);
        return;
    }
    for(int i = 0; i < k - 1 && temp; i++){
        temp = temp->next;
    }
    if(!temp || !temp->next){
        return;
    }
    Node* to_be_deleted = temp->next;
    temp->next = to_be_deleted->next;
    delete to_be_deleted;
}

void remove_dups(Node* &head){
    if(!head || !head->next)    return;
    Node* cur = head;
    while(cur && cur->next){
        if(cur->data == cur->next->data){
            Node* dup = cur->next;
            cur = dup->next;
            delete dup;
        }else cur = cur->next;
    }
}

bool palindrome_check(Node* &head){
    if(!head || !head->next)    return true;
    Node* slow = head, *fast = head;
    while(fast->next && fast->next->next){
        slow = slow->next;
        fast = fast->next->next;
    }
    Node* first = head;
    Node* store = reverse(slow->next), *second = store;
    int yes = 1;
    while(second){
        if(first->data != second->data){
            yes = 0;
            break;
        }
        first = first->next;
        second = second->next;
    } 
    slow->next = reverse(store);
    return yes;
}

void display(Node* head){
    Node* temp = head;
    while(temp){
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}


int main(){
    Node* head = nullptr;
    insert_at_head(head, 3);
    insert_at_tail(head, 5);
    insert_at_tail(head, 7);
    insert_at_k(head, 10, 2); // Insert at position 2
    display(head); // 3 -> 5 -> 10 -> 7 -> NULL
    reverse(head);
    display(head); // 7 -> 10 -> 5 -> 3 -> NULL
    return 0;
}
