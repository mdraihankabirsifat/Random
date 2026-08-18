#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define tata "\n"
#define vr(v, x) vector<ll> v(x)
#define loop(i, j, n) for (ll i = j; i < n; i++)
#define in(v) loop(i, 0, v.size()) cin >> v[i]
#define out(v) loop(i, 0, v.size()) cout << v[i] << " "

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll n;
    cin >> n;

    vr(v, n);
    in(v);

    unordered_set<ll> st;

    // vector -> unordered_set
    for (ll x : v)
    {
        st.insert(x);
    }

    // insert manually
    ll x;
    cin >> x;
    st.insert(x);

    // output / traverse
    for (ll x : st)
    {
        cout << x << " ";
    }
    cout << tata;

    return 0;
}