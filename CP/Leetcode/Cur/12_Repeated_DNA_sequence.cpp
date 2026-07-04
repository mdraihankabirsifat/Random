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
    vector<string> findRepeatedDnaSequences(string s)
    {
        vector<string> dna;
        unordered_map<string, int> m;
        if (s.size() < 10)
        {
            return dna;
        }
        for (int i = 0; i <= s.size() - 10; i++)
        {
            m[s.substr(i, 10)]++;
        }
        for (auto x : m)
        {
            if (x.second > 1)
            {
                cout << x.first << tata;
                dna.push_back(x.first);
            }
        }
        return dna;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s = "AAAAAAAAAAA";
    Solution sol;
    sol.findRepeatedDnaSequences(s);
    return 0;
}