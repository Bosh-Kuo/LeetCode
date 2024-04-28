/*
time complexity: O(N*K), N = Sum(nums), K = nums.length
tags: Array, Dynamic Programming
note: 目標為用 nums 裡的元素加總為 Sum(nums)/2，若 Sum(nums) 為奇數，則直接回傳 false
用 dp[i] 代表 i 是否可以 用 nums 裡的元素加總為 i，最終回傳的答案及為 dp[Sum(nums)/2]
for x in nums: dp[i] = dp[i] || dp[i-x]
reference: https://leetcode.com/problems/partition-equal-subset-sum/solutions/1624365/c-easy-to-solve-beginner-friendly-detailed-explanation-with-a-dry-run/?envType=list&envId=p6idgg6t
*/

class Solution
{
public:
    bool canPartition(vector<int> &nums)
    {
        int sum = 0, target = 0;
        for (auto &n : nums)
            sum += n;

        if (sum % 2 != 0)
            return false;
        else
            target = sum / 2;

        // dp[i] 表示 i 是否可以為 nums 的 subset 的加總
        vector<bool> dp(target + 1, false);
        dp[0] = true;
        for (auto x : nums)
        {
            for (int i = target; i >= x; i--)
            {
                dp[i] = dp[i] || dp[i - x];
                if (i == target && dp[i])
                    return true;
            }
        }
        return dp[target];
    }
};