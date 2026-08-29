class Solution
{
public:
    vector<string> largestString(vector<int> &v)
    {
        int n = v.size();
        vector<string> ans(n);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < 25; j++)
            {
                if (v[i] & (1 << j))
                {
                    ans[i] += char('a' + j);
                }
            }
            ans[i] += string(v[i] >> 25, 'z');
            reverse(ans[i].begin(), ans[i].end());
        }
        return ans;
    }
};