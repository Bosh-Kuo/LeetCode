/*
time complexity:
tags: Array, Math, Randomized
note:
*/

class Solution
{
private:
    vector<int> originalNums;
    vector<int> nums;
    default_random_engine seed;

public:
    Solution(vector<int> &nums) : nums(nums), originalNums(nums), seed(random_device{}())
    {
    }

    vector<int> reset()
    {
        return originalNums;
    }

    vector<int> shuffle()
    {
        for (int i = 0; i < size(nums) - 1; i++)
        {
            auto idx = uniform_int_distribution<int>(i, size(nums) - 1)(seed);
            swap(nums[i], nums[idx]);
        }
        return nums;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */