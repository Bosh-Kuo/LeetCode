/**
time complexity: O(n*log(n))
tags: Array, Two Pointers, Greedy, Sorting
note: 遍歷所有 g，尋找是否滿足 s[s_idx] >= g[g_idx] 的 s[s_idx]，並確保滿足條件的 s[s_idx] 為所有可滿足條件的 s[j] 中的最小值
*/

class Solution
{
public:
    int findContentChildren(vector<int> &g, vector<int> &s)
    {
        // 先把 g, s 由小到大排好
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int ans = 0;
        int g_idx = 0, s_idx = 0;
        int g_size = g.size();
        int s_size = s.size();
        while (g_idx < g_size)
        {
            // 尋找是否滿足 s[s_idx] >= g[g_idx] 的 s[s_idx]
            while (s_idx < s_size)
            {
                if (s[s_idx] >= g[g_idx])
                {
                    ans++;
                    s_idx++;
                    break;
                }
                else
                    s_idx++;
            }
            g_idx++;
        }
        return ans;
    }
};