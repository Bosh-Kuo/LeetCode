/*
time complexity: O(n*log(n))
tags: Array, Binary Search, Dynamic Programming, Sorting
note: 在 n 個 jobs 中從 endTime 最小的 job 遍歷到 endTime 最大的 job，累積計算計算走到不同 endTime 時所能累積的最大 profit。
1. 先將 job 組合成 {endTime, startTime, profit}，並根據 endTime 由小到大排序
2. 定義 dp array: dp[i] = 到第 i 個 endTime 為止累積的最大 profit
3. 定義 dp 關係式: dp[i] = max(當前 job 的 profit + 離當前 job 最近的前一個不衝突 endTime 的 dp 值, 前一個 endTime 的 dp)
4. 回傳 dp[n-1]
*/

class Solution
{
public:
    int jobScheduling(vector<int> &startTime, vector<int> &endTime, vector<int> &profit)
    {
        int n = startTime.size();
        vector<vector<int>> jobs(n);
        for (int i = 0; i < n; ++i)
        {
            jobs[i] = {endTime[i], startTime[i], profit[i]};
        }
        // 將 jobs 根據 endTime 由小排到大
        sort(jobs.begin(), jobs.end());

        vector<int> dp(n);
        dp[0] = jobs[0][2]; // 第一個 endTime 的 dp 值即為本身的 profit

        for (int i = 1; i < n; i++)
        {
            // binary search 找出離當前 job 最近的前一個不衝突 endTime 的 index
            int l = 0, r = i;
            while (l < r)
            {
                int mid = (l + r) / 2;
                if (jobs[mid][0] <= jobs[i][1])
                {
                    l = mid + 1;
                }
                else
                {
                    r = mid;
                }
            }
            int currentProfit = jobs[i][2] + (l > 0 ? dp[l - 1] : 0);
            dp[i] = max(dp[i - 1], currentProfit);
        }
        return dp[n - 1];
    }
};