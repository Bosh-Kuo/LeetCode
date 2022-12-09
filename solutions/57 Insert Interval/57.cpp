/*
time complexity: O(n)
tags: Array
note: 先將完全在 newInterval 左邊的 interval 加入答案，接著處理與 newInterval 有重疊的 interval，合併成一個新的 newInterval，不再有 interval 重疊後把 newInterval 加入答案，
最後把剩餘完全在 newInterval 右半邊的 interval 加入答案
*/

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Solution
{
public:
    vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval)
    {
        vector<vector<int>> Ans;
        int idx = 0, length = intervals.size();

        // 完全在 newInterval 左邊的 interval
        while (idx < length && intervals[idx][1] < newInterval[0])
        {
            Ans.push_back(intervals[idx]);
            idx++;
        }

        // 跟 newInterval 重疊的 interval
        while(idx < length && intervals[idx][0] <= newInterval[1])
        {
            newInterval[0] = min(newInterval[0], intervals[idx][0]);
            newInterval[1] = max(newInterval[1], intervals[idx][1]);
            idx++;
        }
        Ans.push_back(newInterval);

        // 剩下完全在 newInterval 右半邊的 interval
        while(idx < length)
        {
            Ans.push_back(intervals[idx]);
            idx++;
        }
        return Ans;
    }
};
int main()
{
    vector<vector<int>> intervals = {{1,3}, {6,9}};
    vector<int> newInterval = {2,5};
    Solution sol;
    vector<vector<int>> Ans = sol.insert(intervals, newInterval);
    for (auto interval: Ans)
        cout << interval[0] << " " << interval[1] << endl;
}