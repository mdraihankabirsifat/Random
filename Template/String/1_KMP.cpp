#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define tata "\n"

vector<ll> buildLPS(string pattern)
{
    ll n = pattern.size();
    vector<ll> lps(n, 0);

    ll len = 0;
    ll i = 1;

    while (i < n)
    {
        if (pattern[i] == pattern[len])
        {
            len++;
            lps[i] = len;
            i++;
        }
        else
        {
            if (len != 0)
            {
                len = lps[len - 1];
            }
            else
            {
                lps[i] = 0;
                i++;
            }
        }
    }

    return lps;
}

vector<ll> kmpSearch(string text, string pattern)
{
    vector<ll> positions;
    vector<ll> lps = buildLPS(pattern);

    ll n = text.size();
    ll m = pattern.size();

    ll i = 0;
    ll j = 0;

    while (i < n)
    {
        if (text[i] == pattern[j])
        {
            i++;
            j++;
        }

        if (j == m)
        {
            positions.pb(i - j);
            j = lps[j - 1];
        }
        else if (i < n && text[i] != pattern[j])
        {
            if (j != 0)
            {
                j = lps[j - 1];
            }
            else
            {
                i++;
            }
        }
    }

    return positions;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string text, pattern;
    cin >> text >> pattern;

    vector<ll> positions = kmpSearch(text, pattern);

    if (positions.empty())
    {
        cout << "Not Found" << tata;
    }
    else
    {
        for (ll pos : positions)
        {
            cout << pos << " ";
        }
        cout << tata;
    }

    return 0;
}