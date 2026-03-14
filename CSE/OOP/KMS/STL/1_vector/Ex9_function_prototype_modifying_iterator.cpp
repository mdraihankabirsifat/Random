#include <iostream>
#include <vector>
using namespace std;

// Iterator

// iterator begin();
// iterator end();
// reverse_iterator rbegin();
// reverse_iterator rend();

// Iterator-based Operations

// iterator insert (iterator pos, const value_type & val);
// insert single element

// void insert (iterator pos, size_type n, const value_type & val);
// insert n copies

// template <class InputIterator>
// void insert (iterator pos, InputIterator first, InputIterator last);
// range insert

// iterator erase (iterator pos);
// remove single element

// iterator erase (iterator first, iterator last);
// remove range

// void assign (size_type n, const value_type & val);
// assign n copies

// template <class InputIterator>
// void assign (InputIterator first, InputIterator last);
// range assign

int main()
{
    vector<int> v = {10, 20, 30, 40};

    // using iterator
    vector<int>::iterator it;

    for (it = v.begin(); it != v.end(); it++)
        cout << *it << " ";

    cout << endl;

    // reverse iterator
    vector<int>::reverse_iterator rit;

    for (rit = v.rbegin(); rit != v.rend(); rit++)
        cout << *rit << " ";

    cout << endl;

    // insert element
    v.insert(v.begin() + 1, 99);

    // erase element
    v.erase(v.begin() + 2);

    // assign new values
    v.assign(3, 5);

    cout << "Vector after assign: ";

    for (int x : v)
        cout << x << " ";

    return 0;
}

/*
Key Notes
---------
begin()  -> iterator to first element
end()    -> iterator to position after last

rbegin() -> reverse start
rend()   -> reverse end

insert() -> insert element(s)
erase()  -> remove element(s)
assign() -> replace vector contents
*/