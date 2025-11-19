#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define msort(x) sort(x.begin(), x.end())
#define endl '\n'
#define loop(i, n) for (int i = 0; i < n; i++)
using namespace std;

class Solution
{
public:
    bool isPalindrome(int x)
    {
        string s1 = to_string(x);
        string s2 = s1;
        reverse(s1.begin(), s1.end());
        if (s1 == s2)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int x;
    cin >> x;
    Solution sol;
    if (sol.isPalindrome(x))
    {
        cout << "true";
    }
    else
    {
        cout << "false";
    }
    return 0;
}