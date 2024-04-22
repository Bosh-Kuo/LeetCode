/*
time complexity: O(n*target)
tags: Array, Dynamic Programming
note: 令 dp[i] 的值代表 combinationSum4(nums, i)
dp[i] = dp[i-num] for num in nums
*/

class Solution
{
public:
    int combinationSum4(vector<int> &nums, int target)
    {
        if (*min_element(nums.begin(), nums.end()) > target)
            return 0;
        vector<unsigned int> dp(target + 1, 0);

        for (int i = 0; i <= target; i++)
        {
            for (auto num : nums)
            {
                if (num > i)
                    continue;
                else if (num == i)
                    dp[i] += 1;
                else
                    dp[i] += dp[i - num];
            }
        }
        return dp[target];
    }
};