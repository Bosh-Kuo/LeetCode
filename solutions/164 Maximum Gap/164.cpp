/*
time complexity: O(nlog(n))
tags: Array, Sorting, Bucket Sort, Radix Sort
note: 本題最佳解是用 linear time 的 sorting 演算法，可用 bucket sort or radix sort 等避免試用過多儲存空間
*/

class Solution
{
public:
    int maximumGap(vector<int> &nums)
    {
        if (nums.size() < 2)
            return 0;

        sort(nums.begin(), nums.end());
        int max = 0;
        for (int i = 1; i < nums.size(); i++)
        {
            int diff = nums[i] - nums[i - 1];
            if (diff > max)
                max = diff;
        }
        return max;
    }
};