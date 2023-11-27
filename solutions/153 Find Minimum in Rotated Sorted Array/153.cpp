/*
time complexity: O(n)
tags: Array, Binary Search
note: 若 nums[left] < nums[right]，代表沒有 rotate，直接 return nums[left]
若 nums[mid] < nums[right]，代表最小值一定不會出現在 mid 右半邊
若 nums[mid] > nums[right]，代表最小值一定不會出現在 mid 以及 mid 左半邊
*/
class Solution
{
public:
    int findMin(vector<int> &nums)
    {
        int left = 0, right = nums.size() - 1;

        while (left < right)
        {
            if (nums[left] < nums[right])
                return nums[left];

            int mid = (left + right) / 2;
            if (nums[mid] > nums[right])
                left = mid + 1;
            else
                right = mid;
        }
        return nums[left];
    }
};