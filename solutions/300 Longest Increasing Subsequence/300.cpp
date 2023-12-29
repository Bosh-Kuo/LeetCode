/*
time complexity: O(nlog(n))
tags: Array, Binary Search, Dynamic Programming
note: 建立一個 equivalentSeq，維持它的長度等於 longest strictly increasing subsequence (LIS) 的長度
，同時維持其最後一個元素為所有可能的 LIS 中的最小值。
[1,2,7,8,3,4,5,9,0]
1 -> [1]
2 -> [1,2]
7 -> [1,2,7]
8 -> [1,2,7,8]
3 -> [1,2,3,8]  // we replaced 7 with 3, since for the longest sequence we need only the last number and 1,2,3 is our new shorter sequence
4 -> [1,2,3,4] // we replaced 8 with 4, since the max len is the same but 4 has more chances for longer sequence
5 -> [1,2,3,4,5]
9 -> [1,2,3,4,5,9]
0 -> [0,2,3,4,5,9] // we replaced 1 with 0, so that it can become a new sequence
*/

class Solution
{
public:
    int lengthOfLIS(vector<int> &nums)
    {
        vector<int> equivalentSeq;
        equivalentSeq.push_back(nums[0]);
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] > equivalentSeq.back())
                equivalentSeq.push_back(nums[i]);
            else
            {
                auto lowerBound = lower_bound(equivalentSeq.begin(), equivalentSeq.end(), nums[i]);
                *lowerBound = nums[i];
            }
        }
        return equivalentSeq.size();
    }
};