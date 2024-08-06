/*
time complexity: O(n*log(n))
tags: Array, Heap(Priority Queue)
note: 用 max heap 儲存所有數，每次 pop 最大的兩個，若兩者不同則將兩兩相減的值 push 回 max heap。直到 max heap 大小小於等於 1 為止
*/

class Solution
{
public:
    int lastStoneWeight(vector<int> &stones)
    {
        priority_queue<int> maxHeap(stones.begin(), stones.end());
        while (maxHeap.size() > 1)
        {
            int y = maxHeap.top();
            maxHeap.pop();
            int x = maxHeap.top();
            maxHeap.pop();
            if (x != y)
                maxHeap.push(y - x);
        }
        if (maxHeap.size() > 0)
            return maxHeap.top();
        else
            return 0;
    }
};