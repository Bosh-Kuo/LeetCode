/*
time complexity : O(n^2)
tags: Array, Two Pointers, Sorting
note: 1. 排序 nums 2. 從 i = 0 to i = n-3，固定 set 中的最小值，令 left = i+1, right = n-1，用 two pointer 尋找最接近 target 的總和
*/

class Solution
{
public:
    int threeSumClosest(vector<int> &nums, int target)
    {
        int n = nums.size();
        // 1. 排序 nums
        sort(nums.begin(), nums.end());
        // 2. 從 i = 0 to i = n-3，固定 set 中的最小值，令 left = i+1, right = n-1，用 two pointer 尋找最接近 target 的總和
        int closestSum = nums[0] + nums[1] + nums[2];
        if (closestSum == target)
            return closestSum;

        for (int i = 0; i < n - 2; i++)
        {
            int left = i + 1, right = n - 1;
            while (left < right)
            {
                int temp = nums[i] + nums[left] + nums[right];
                if (abs(target - temp) < abs(target - closestSum))
                    closestSum = temp;
                if (temp == target)
                    return target;
                else if (temp > target)
                    right -= 1;
                else
                    left += 1;
            }
        }
        return closestSum;
    }
};