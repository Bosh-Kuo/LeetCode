/*
time complexity: O(n)
tags: Array, Stack, Monotonic Stack
note:
用 monotonic stack 維護一個嚴格遞增的 stack s，stack 內儲存 {temperature, index}，紀錄還未找到答案的 index
當 temperatures[i] > s.top.first() 時， s.top().second 所在的 index 與 i 的距離及為 index 的答案
*/

class Solution
{
public:
    vector<int> dailyTemperatures(vector<int> &temperatures)
    {

        int n = temperatures.size();
        stack<pair<int, int>> s;
        vector<int> ans(n, 0);

        for (int i = 0; i < n; i++)
        {
            while (!s.empty() && temperatures[i] > s.top().first)
            {
                int lastIdx = s.top().second;
                ans[lastIdx] = i - lastIdx;
                s.pop();
            }
            s.push({temperatures[i], i});
        }
        return ans;
    }
};