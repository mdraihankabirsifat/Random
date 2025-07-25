#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, i = 0;
        cin >> n;
        deque<int> v(1001);
        while (n > 0)
        {
            i++;
            int a = n % 10;
            v.push_front(a);
            n = n / 10;
        }
        cout << *min_element(v.begin(), v.begin() + i) << endl;
    }
    return 0;
}