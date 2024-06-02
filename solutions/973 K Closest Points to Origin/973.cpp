/*
time complexity: O(n*log(n))
tags: Array, Math, Divide and Conquer, Geometry, Sorting, Heap(Priority Queue), Quickselect
note: 自定義 MinHeapComparator，建立 minHeap 來儲存座標。需要將 vector 轉為 pair 再存入 minHeap，否則速度會很慢
*/

class Solution
{
public:
    struct MinHeapComparator
    {
        bool operator()(pair<int, int> lhs, pair<int, int> rhs)
        {
            return (lhs.first * lhs.first + lhs.second * lhs.second) > (rhs.first * rhs.first + rhs.second * rhs.second);
        }
    };
    vector<vector<int>> kClosest(vector<vector<int>> &points, int k)
    {
        vector<vector<int>> ans;
        priority_queue<pair<int, int>, vector<pair<int, int>>, MinHeapComparator> minHeap;

        for (auto &point : points)
        {
            minHeap.push({point[0], point[1]});
        }

        for (int i = 0; i < k; i++)
        {
            ans.push_back({minHeap.top().first, minHeap.top().second});
            minHeap.pop();
        }
        return ans;
    }
};