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