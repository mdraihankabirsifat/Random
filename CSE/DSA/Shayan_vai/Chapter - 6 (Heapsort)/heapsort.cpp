#include<bits/stdc++.h>
using namespace std;

int parent(int i){return i / 2;}
int left(int i) {return 2 * i;}
int right(int i){return 2 * i + 1;}

// Recursive
void max_heapify(vector<int>& a, int i){
    int l = left(i), r = right(i);
    int n = a.size() - 1, mx;
    if(l > n)   return;
    if(r > n)   mx = l;
    else mx = (a[l] > a[r]) ? l : r;
    if(a[mx] <= a[i])    return;
    swap(a[i], a[mx]);
    max_heapify(a, mx);
}

void build_max_heap(vector<int>&a){
    int n = a.size() - 1;
    for(int i = n / 2; i >= 1; i--){
        max_heapify(a, i);
    }
}

vector<int>&heapsort(vector<int>&a){
    build_max_heap(a);
    vector<int>res;
    int n = a.size() - 1;
    for(int i = n; i >= 2; i--){
        swap(a[1], a[i]);
        res.push_back(a[i]);
        a.pop_back();
        max_heapify(a, i);
    }
    res.push_back(a[1]);
    reverse(res.begin(), res.end());
    return res;
}