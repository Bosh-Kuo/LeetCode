/*
time complexity: O(Log(n)) For Add, O(n*Log(n)) For Constructor
tags: Tree, Design, Binary Search Tree, Heap(Priority Queue), Binary Tree, Data Stream
note: 使用 minHeap 儲存 nums，只保留最後 k 個數，一旦超過即 pop
*/

class KthLargest
{
private:
    int k;
    priority_queue<int, vector<int>, greater<int>> minHeap;

public:
    KthLargest(int k, vector<int> &nums) : k(k)
    {
        for (auto n : nums)
        {
            minHeap.push(n);
            if (minHeap.size() > k)
                minHeap.pop();
        }
    }

    int add(int val)
    {
        minHeap.push(val);
        if (minHeap.size() > k)
            minHeap.pop();
        return minHeap.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */