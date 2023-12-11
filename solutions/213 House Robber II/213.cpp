/*
time complexity: O(n)
tags: Array, Dynamic Programming
note: 現在 nums[0] 與 nums[n-1] 不能同時取，這相當於是求 i = 0 ~ n-2 與 i = 1 ~ n-1 兩種範圍的 DP 最大值
DP 關係式為 DP[i] = max(DP[i-1], DP[i-2]+nums[i])
*/

class Solution
{
public:
    int rob(vector<int> &nums)
    {
        int n = nums.size();
        if (n < 2)
            return n ? nums[0] : 0;
        return max(robber(nums, 0, n - 2), robber(nums, 1, n - 1));
    }

private:
    int robber(vector<int> &nums, int l, int r)
    {
        int pre = 0, cur = 0;
        for (int i = l; i <= r; i++)
        {
            int temp = max(pre + nums[i], cur);
            pre = cur;
            cur = temp;
        }
        return cur;
    }
};