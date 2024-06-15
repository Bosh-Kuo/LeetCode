/*
time complexity: O(n)
tags: Array, Two Pointers
note: ex: 1241'2'54'3' -> 1241'3'54'2' -> 12413254
1. 找出滿足以下條件的最大 index k : nums[k] < nums[k+1]，若沒有任何 index 符合，直接 reverse nums
2. 找出滿足以下條件的最大 index l : l > k && nums[k] < nums[l]
3. 先互換 l, k 的位置， 再將 nums[k+1:] reverse
*/

class Solution
{
public:
    void nextPermutation(vector<int> &nums)
    {
        // ex: 1241'2'54'3' -> 1241'3'54'2' -> 12413254
        int n = nums.size(), k, l;
        for (k = n - 2; k >= 0; k--)
        {
            if (nums[k] < nums[k + 1])
            {
                break;
            }
        }
        // 若沒任何 index 滿足，直接 reverse
        if (k < 0)
        {
            reverse(nums.begin(), nums.end());
        }
        else
        {
            for (l = n - 1; l > k; l--)
            {
                // 找出滿足以下條件的最大 index l : l > k && nums[k] < nums[l]
                if (nums[l] > nums[k])
                {
                    break;
                }
            }
            // 先互換 l, k 的位置
            swap(nums[k], nums[l]);
            // 再將 nums[k+1:] reverse
            reverse(nums.begin() + k + 1, nums.end());
        }
    }
};