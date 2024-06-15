/*
time complexity: O(n)
tags: Array, Queue, Sliding Window, Heap(Priority Queue), Monotonic Queue
note:
用 deque 儲存 index，維持 [大 -> 小], [舊 -> 新] 的關係，當目前走訪的 index 已不再 window 內時必須把該 index 移除
因此必須確保剛走過該 index 時，該 index 在 deque 裡不是在頭，不然就是不在 deque 裡。
走到 i 時，把比 nums[i] 小的數的 index 都移出 deque，因為這些 index 都比 i 還舊，且不可能越過 i 成為 window 的最大值
=> deque 中排在 i 前面的，只可能是比 nums[i] 還大的數的 index
*/

class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        deque<int> idxQueue;
        vector<int> ans;

        for (int i = 0; i < nums.size(); i++)
        {
            // 把比 nums[i] 小的數的 index 都移出，因為這些 index 都比 i 還舊，且不可能越過 i 成為 window 的最大值
            while (!idxQueue.empty() && nums[idxQueue.back()] < nums[i])
                idxQueue.pop_back();

            // idxQueue 中排在 i 前面的，只可能是比 nums[i] 還大的數的 index
            idxQueue.push_back(i);

            // 從 index 走到 k - 1 開始才會有完整的 window
            if (i < k - 1)
                continue;
            else
            {
                // 小於等於 i - k 的 index 已不再 window 裡
                if (i - k == idxQueue.front())
                    idxQueue.pop_front();

                ans.push_back(nums[idxQueue.front()]);
            }
        }
        return ans;
    }
};