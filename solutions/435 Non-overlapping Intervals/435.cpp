/*
time complexity: O(n*log(n))
tags: Array, Dynamic Programming, Greedy, Sorting
note:
1. 逐一判斷 overlay 的前提條件是，該 array 必須是經過排序的。
2. 由於 interval[0] < interval[1]，若依照 intervals[i][1] 由小到大排列則可直接用 interval[i][1] 是否大於 interval[i+1][0] 來判斷 overlay
3. 排序好 intervals 後，逐一檢查前後是否發生 overlay，若發生 overlay 則捨棄後者，因為 prev[1] 必小於等於 current[1]。
   ，若要捨棄最少 interval， prev[1] 必須越小越好，因為 prev[1] 越大越容易 overlay
*/

class Solution
{
public:
    static bool comp(vector<int> &a, vector<int> &b)
    {
        return a[1] < b[1];
    }
    int eraseOverlapIntervals(vector<vector<int>> &intervals)
    {
        // 依照 end 由小到大排列: [[1,2],[1,3],[2,3],[3,4]]
        sort(intervals.begin(), intervals.end(), comp);
        int ans = -1;

        vector<int> prev = intervals[0];
        for (auto current : intervals)
        {
            if (prev[1] > current[0])
                ans++; // 當發生 overlay 時，捨棄掉 current，保留 prev，因為 prev[1] 必小於等於 current[1]。若要捨棄最少 interval， prev[1] 必須越小越好，因為 prev[1] 越大越容易 overlay
            else
                prev = current; // 沒發生 overlay 則更新 prev
        }
        return ans;
    }
};