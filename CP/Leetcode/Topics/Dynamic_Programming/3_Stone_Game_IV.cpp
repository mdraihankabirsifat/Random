// https://leetcode.com/problems/stone-game-iv/
/*
Problem: Stone Game IV

Players alternately remove a nonzero square number of stones; determine
whether the first player can force a win with optimal play.
*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define tata "\n"
#define yes cout << "YES" << tata
#define no cout << "NO" << tata

class Solution
{
public:
    bool winnerSquareGame(int n)
    {
        vector<bool> dp(n + 1);
        for (int i = 0; i <= n; i++)
        {
            if (!dp[i])
            {
                for (int j = 1; i + j * j <= n; j++)
                {
                    dp[i + j * j] = true;
                }
                if (dp[n])
                {
                    return true;
                }
            }
        }
        return false;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Solution sol;
    ll n = 4;
    bool p = sol.winnerSquareGame(n);
    if (p)
        yes;
    else
        no;
    return 0;
}
