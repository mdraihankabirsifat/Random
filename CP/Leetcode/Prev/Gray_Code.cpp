#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define tata "\n"
#define vr(v, x) vector<ll> v(x)
#define vrr(v, x, y) vector<vector<ll>> v(x, vector<ll>(y))
#define jora(p, n) pair<ll, ll> p(n)
#define sajai(x) sort(x.begin(), x.end())
#define rsort(a) sort(a.begin(), a.end(), greater<>())
#define ulta(a) reverse(a.begin(), a.end())
#define mucho(a, j) a.erase(a.begin() + j)
#define choto(a) *min_element(a.begin(), a.end())
#define boro(a) *max_element(a.begin(), a.end())
#define jog(a) accumulate(a.begin(), a.end(), 0LL)
#define bit(n) __builtin_popcountll(n)
#define loop(i, j, n) for (ll i = j; i < n; i++)
#define in(v) loop(i, 0, v.size()) cin >> v[i]
#define out(v) loop(i, 0, v.size()) cout << v[i] << " "
#define yes cout << "YES" << tata
#define no cout << "NO" << tata

class Solution
{
public:
    vector<int> grayCode(int n)
    {
        int x = pow(2, n);
        vector<int> v;
        v.push_back(0);
        v.push_back(1);
        if (n == 1)
        {
            return v;
        }
        v.push_back(3);
        v.push_back(2);
        for (int i = 3; i <= n; i++)
        {
            int j = (i - 2);
            vector<int> v1;
            v1 = v;
            reverse(v1.begin(), v1.end());
            for (int k = 0; k < v1.size(); k++)
            {
                v.push_back(v1[k] + pow(2, j + 1));
            }
        }
        return v;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    Solution sol;
    vector<int> v;
    v = sol.grayCode(n);
    out(v);
    return 0;
}