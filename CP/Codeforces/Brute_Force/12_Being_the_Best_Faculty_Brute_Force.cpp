#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define jora(p, n) pair<ll, ll> p(n)
#define sajai(x) sort(x.begin(), x.end())
#define arr(v, x, y) vector<vector<double>> v(x, vector<int>(y))
#define loop(i, j, n) for (ll i = j; i < n; i++)
#define in(v) loop(i, 0, v.size()) cin >> v[i]
#define out(v) loop(i, 0, v.size()) cout << v[i] << " "
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define db double
#define tata "\n"
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, x = 0;
    cin >> n;
    vector<vector<db>> v(n, vector<db>(3));
    vector<db> c1 = {0, 50};
    loop(i, 0, n)
    {
        cin >> v[i][0] >> v[i][1] >> v[i][2];
        db a = v[i][0], b = v[i][1], c = v[i][2];
        if (a != b)
        {
            db w = (8000 - 50 * (b + c)) / (a - b);
            if (w >= 0 && w <= 50)
            {
                c1.pb(w);
            }
        }
    }
    loop(i, 0, c1.size())
    {
        ll c2 = 0;
        loop(j, 0, n)
        {
            db a = v[j][0], b = v[j][1], c = v[j][2];
            db t = a * c1[i] + b * (50 - c1[i]) + 50 * c;
            if (t >= 8000)
            {
                c2++;
            }
        }
        x = max(x, c2);
    }
    cout << x << tata;
    return 0;
}