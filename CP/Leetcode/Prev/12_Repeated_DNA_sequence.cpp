#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define tata "\n"

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