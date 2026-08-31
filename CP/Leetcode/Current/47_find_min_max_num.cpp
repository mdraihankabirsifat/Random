// 2058
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define tata "\n"
#define sajai(x) sort(x.begin(), x.end())
#define loop(i, j, n) for (ll i = j; i < n; i++)
#define in(v) loop(i, 0, v.size()) cin >> v[i]
#define out(v) loop(i, 0, v.size()) cout << v[i] << " "

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    vector<int> nodesBetweenCriticalPoints(ListNode *head)
    {
        ListNode *x = head;
        int i = 2, min = -1, max = -1, l = x->val;
        x = x->next;
        vector<int> gap = {}, ans(2, -1);
        while (x != nullptr && x->next != nullptr)
        {
            int cur = x->val, r = x->next->val;
            if ((l > cur && cur < r) || (l < cur && cur > r))
            {
                gap.pb(i);
                cout << l << " " << cur << " " << r << tata;
            }
            // cout << x->val << " ";
            l = cur;
            x = x->next;
            i++;
        }
        //[6,8,4,1,9,6,6,10,6]
        int n = gap.size();
        if (n > 1)
        {
            sajai(gap);
            out(gap);
            cout << tata;
            int y = INT_MAX;
            for (int i = 1; i < n; i++)
            {
                if (gap[i] - gap[i - 1] < y)
                {
                    ans[0] = gap[i] - gap[i - 1];
                    y = gap[i] - gap[i - 1];
                }
            }
            ans[1] = gap[n - 1] - gap[0];
        }
        out(ans);
        return ans;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ListNode *head = new ListNode(6);
    head->next = new ListNode(8);
    head->next->next = new ListNode(4);
    head->next->next->next = new ListNode(1);
    head->next->next->next->next = new ListNode(9);
    head->next->next->next->next->next = new ListNode(6);
    head->next->next->next->next->next->next = new ListNode(6);
    head->next->next->next->next->next->next->next = new ListNode(10);
    head->next->next->next->next->next->next->next->next = new ListNode(6);
    Solution sol;
    sol.nodesBetweenCriticalPoints(head);
    return 0;
}