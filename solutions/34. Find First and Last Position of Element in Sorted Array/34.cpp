/*
time complexity: O(log(n))
tags: Array, Binary Search
note:
找 first: 只有 nums[mid] < target 才移動左邊界，其他情況都只移動右邊界
找 last: 只有 nums[mid] > target 才移動右邊界，其他情況都只移動左邊界
*/

class Solution
{
public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        int first = -1, last = -1;
        int left = 0, right = nums.size() - 1;

        // Find the first position
        while (left <= right)
        {
            int mid = (left + right) / 2;
            if (nums[mid] < target)
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }
        if (left < nums.size() && nums[left] == target)
        {
            first = left;
        }

        // Reset bounds for finding the last position
        left = 0;
        right = nums.size() - 1;

        // Find the last position
        while (left <= right)
        {
            int mid = (left + right) / 2;
            if (nums[mid] > target)
            {
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }
        if (right >= 0 && nums[right] == target)
        {
            last = right;
        }

        return {first, last};
    }
};
