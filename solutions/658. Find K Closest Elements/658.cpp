/*
time complexity: O(n)
tags: Array, Two Pointers, Binary Search, Sliding Window, Sorting, Heap(Priority Queue)
note: 使用 deque 暫存 arr，再透過 two pointers 從一頭一尾比較，pop 掉距離 x 比較遠者
*/

class Solution
{
public:
    vector<int> findClosestElements(vector<int> &arr, int k, int x)
    {
        vector<int> ans;
        int length = arr.size();

        // 先用 dequeu 暫存整個 arr
        deque<int> dq;
        for (auto &e : arr)
            dq.push_back(e);

        // 用 two-pointer 從 idx = 0, idx = length - 1 兩兩比對
        int leftIdx = 0, rightIdx = arr.size() - 1;
        while (length > k)
        {
            int left = dq.front();
            int right = dq.back();
            if (abs(x - left) > abs(x - right))
                dq.pop_front();
            else if (abs(x - left) < abs(x - right))
                dq.pop_back();
            else
                dq.pop_back();
            length--;
        }

        for (auto it = dq.begin(); it != dq.end(); ++it)
        {
            ans.push_back(*it);
        }

        return ans;
    }
};