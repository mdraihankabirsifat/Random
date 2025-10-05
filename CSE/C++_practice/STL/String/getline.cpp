#include <bits/stdc++.h>
using namespace std;
int main()
{
    string a;
    getline(cin, a); // take input space also
    cout << a << endl;
    int t;
    cin >> t;
    cin.ignore(); //move the cursor to the next line
    while (t--)
    {
        getline(cin, a);
        cout << a << endl;
    }
    return 0;
}