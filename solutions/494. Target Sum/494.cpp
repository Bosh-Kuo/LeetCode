/*
time complexity: O(n * positive)
tags: Array, Dynamic Programming, Backtracking
note: 可以把問題分成轉化成找出子集合個數的問題。把正數與負數分成兩個集合，目標找出滿足 positive - negative = target 的所有子集個數
positive - negative = target
positive + negative = sum
條件：positive 與 negative 皆大於 0 且為整數, num > target
定義 dp[i] 表示有多少種方法可以使得和為 i
遍歷每一個數字 num，更新 DP，從 positive 開始到 num 遍歷。
dp[i] 的更新方式是 dp[i] += dp[i - num]，這意味著如果我們能夠用 dp[i - num] 來達到 i - num，那麼我們也可以用這個 num 來達到 i。
*/

class Solution
{
public:
    // positive - negative = target
    // positive + negative = sum
    int findTargetSumWays(vector<int> &nums, int target)
    {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum < target || (sum + target) % 2 != 0 || (sum - target) / 2 + target < 0)
            return 0;

        int positive = (sum + target) / 2;

        vector<int> dp(positive + 1, 0);
        dp[0] = 1;

        for (int num : nums)
        {
            for (int i = positive; i >= num; --i)
            {
                dp[i] += dp[i - num];
            }
        }

        return dp[positive];
    }
};
