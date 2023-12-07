/*
time complexity: O(n)
tags: Array, Dynamic Programming
note: 本題為標準 DP 題目，確定 DP array 的定義為，走到 house i 可以取得的最大金額，
DP 關係式為 DP[i] = max(DP[i-1], DP[i-2]+nums[i])
*/

class Solution
{
public:
    int rob(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 0)
            return 0;

        vector<int> dp(n + 1, 0);
        dp[1] = nums[0];
        for (int i = 2; i <= n; i++)
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i - 1]);
        return dp[n];
    }
};