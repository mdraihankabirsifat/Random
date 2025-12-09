#include <bits/stdc++.h>
using namespace std;
string num_to_string(int n)
{
    return to_string(n);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        string s = num_to_string(n);
        cout << s[1] << "\n";
        /*
        in C
        int num = 123;
        char str[20];
        sprintf(str, "%d", num); // convert number to string
        */
    }
    return 0;
}