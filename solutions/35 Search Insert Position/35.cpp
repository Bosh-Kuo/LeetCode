/*
time complexity: O(log(n))
tags: Array, Binary Search
note: 先排除 target 在超出 nums 邊界的情況，在用 binary search 尋找
*/

class Solution
{
public:
    int searchInsert(vector<int> &nums, int target)
    {
        if (target < nums[0])
            return 0;
        else if (target > nums[nums.size() - 1])
            return nums.size();
        else
        {
            int left = 0, right = nums.size();
            while (left < right)
            {
                int mid = (left + right) / 2;
                if (nums[mid] == target)
                    break;
                else if (nums[mid] > target)
                    right = mid;
                else
                    left = mid + 1;
            }
            return (left + right) / 2;
        }
    }
};