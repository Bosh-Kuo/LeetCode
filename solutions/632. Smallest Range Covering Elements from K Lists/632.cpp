/*
time complexity: O(n*m)
tags: Array, Hash Table, Greedy, Sliding Window, Sorting, Heap(Priority Queue)
note: 將每個 list 當前還沒取過所能取得的最小值放入 minHeap 儲存，同時紀錄該座標，可視為一個 sliding window，紀錄 window 內的最大最小值，
並判斷最大最小值是否符合最小 range。每次迭代把 window 內的最小值 pop 出，並加入該值所屬座標的下一個值。

ex:
4, 0, 5
4, 9, 5
10, 9, 5
10, 9, 18
10, 12, 18
15, 12, 18
15, 20, 18
24, 20, 18
24, 20, 22
*/

class Solution
{
public:
    vector<int> smallestRange(vector<vector<int>> &nums)
    {
        vector<int> ans(2);
        // 自定義 minHeap 比較方法
        // minHeap 儲存元素結構 {nums[i][j],{i,j}}
        auto compare = [](pair<int, pair<int, int>> left, pair<int, pair<int, int>> right)
        { return left.first > right.first; };
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, decltype(compare)> minHeap(compare);

        // 先把 {nums[i][0], 0} push 進 minHeap
        // 並且記錄下 min, max
        int maxNum = -100001, minNum = 100001;
        for (int i = 0; i < nums.size(); i++)
        {
            minHeap.push({nums[i][0], {i, 0}});
            maxNum = max(nums[i][0], maxNum);
            minNum = min(nums[i][0], minNum);
        }
        ans[0] = minNum;
        ans[1] = maxNum;

        if (ans[0] == ans[1])
            return ans;

        while (true)
        {
            pair<int, pair<int, int>> lastMinRecord = minHeap.top();
            minHeap.pop();

            pair<int, int> lastMinCoord = lastMinRecord.second;
            int rowIdx = lastMinCoord.first;
            int colIdx = lastMinCoord.second + 1;
            if (colIdx >= nums[lastMinCoord.first].size())
                break;

            minHeap.push({nums[rowIdx][colIdx], {rowIdx, colIdx}});
            pair<int, pair<int, int>> curMinRecord = minHeap.top();
            pair<int, int> curMinCoord = curMinRecord.second;
            // 新加入的值可能會大於 maxNum
            maxNum = max(nums[rowIdx][colIdx], maxNum);
            // minNum 必定為 minHeap.top() 紀錄的值
            minNum = curMinRecord.first;
            if (ans[1] - ans[0] > maxNum - minNum)
            {
                ans[1] = maxNum;
                ans[0] = minNum;
            }
        }

        return ans;
    }
};
