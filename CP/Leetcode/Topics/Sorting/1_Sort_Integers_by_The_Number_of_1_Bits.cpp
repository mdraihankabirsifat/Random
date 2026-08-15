// https://leetcode.com/problems/sort-integers-by-the-number-of-1-bits/
/*
Problem: Sort Integers by The Number of 1 Bits

Sort integers by increasing count of set bits, breaking ties by their
numeric value in ascending order.
*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define sajai(x) sort(x.begin(), x.end())
#define bit(n) __builtin_popcountll(n)

class Solution
{
public:
    vector<int> sortByBits(vector<int> &arr)
    {
        vector<int> v;
        map<int, vector<int>> m;
        ll n = arr.size();
        for (int i = 0; i < n; i++)
        {
            ll p = bit(arr[i]);
            m[p].pb(arr[i]);
        }
        for (int i = 0; i < m.size(); i++)
        {
            sajai(m[i]);
            for (int j = 0; j < m[i].size(); j++)
            {
                v.pb(m[i][j]);
            }
        }
        //out(v);
        return v;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    //cin >> n;
    vector<int> v(n);
    //in(v);
    Solution sol;
    //sol.sortByBits(v);
    return 0;
}
//1024,512,256,128,64,32,16,8,4,2,1
