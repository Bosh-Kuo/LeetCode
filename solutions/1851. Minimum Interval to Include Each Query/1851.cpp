/*
time complexity : O(n*log(n))
tags: Array, Binary Search, Line Sweep, Sorting, Heap(Priority Queue)
note:
1. 先將 intervals, queries 由小到大排好，當，我們遍歷到 query 時就可以只鎖定特定幾個 intervals
2. 但如果直接 sort queries 會打亂 ans 的順序，因此，排序之前先額外記下原本的 index
3. 逐個遍歷 sorted query，將 left <= query 的 intervals 加入 minHeap
4. 若 minHeap.top 所記錄的 interval 的 right < query < 接下來的 query，將該 interval 從 minHeap pop 掉。
5. 如果 minHeap 不為空， minHeap.top 所記錄的 interval 長度即為該 query 的答案，否則代表該 query 找不到對應的 interval，指定為 -1
*/

class Solution
{
public:
    vector<int> minInterval(vector<vector<int>> &intervals, vector<int> &queries)
    {
        int size = queries.size();
        vector<int> ans(size);

        // 1. sort queries, intervals:
        vector<pair<int, int>> queryPairs;
        for (int i = 0; i < size; i++)
        {
            queryPairs.push_back({queries[i], i});
        }
        sort(queryPairs.begin(), queryPairs.end());
        sort(intervals.begin(), intervals.end());

        // 2. create a min heap to store {interval size, right_i}
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;

        // 3. Iterate through sorted queryPairs
        int intervalIdx = 0;
        for (int i = 0; i < size; i++)
        {
            int query = queryPairs[i].first;
            int queryIdx = queryPairs[i].second;
            // Add qualified intervals into minHeap
            while (intervalIdx < intervals.size() && intervals[intervalIdx][0] <= query)
            {
                minHeap.push({intervals[intervalIdx][1] - intervals[intervalIdx][0] + 1, intervals[intervalIdx][1]});
                intervalIdx++;
            }

            // Remove the interval, which's right is smaller than query
            while (!minHeap.empty() && minHeap.top().second < query)
            {
                minHeap.pop();
            }

            if (!minHeap.empty())
                ans[queryIdx] = minHeap.top().first;
            else
                ans[queryIdx] = -1;
        }
        return ans;
    }
};