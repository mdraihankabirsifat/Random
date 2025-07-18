#include <bits/stdc++.h>
using namespace std;

int main()
{
    string a, b, result;
    cin >> a >> b;
    result.push_back(a[0]); // start with first letter of a
    for (int i = 1; i < (int)a.size(); i++)
    {
        if (a[i] < b[0])
            result.push_back(a[i]); // add letters smaller than b[0]
        else
            break;
    }
    result.push_back(b[0]);
    cout << result << "\n";
    return 0;
}