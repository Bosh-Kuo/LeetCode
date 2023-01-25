/*
time complexity: O(n)
tags: Array, Dynamic Programming, Greedy
note: n 個 nodes 的 BST 的總數量就是每個 node 當 head 時的 BST 數量的總和
follow DP 問題 5 步驟：
1. 定義 DP array: DP[i] = 走經過 index i 的路徑中，最遠能走到哪個位置
2. 推導遞迴式: DP[i] = max(DP[i-1], i + nums[i]) if DP[i-1] >= i else DP[i] = -1
3. 初始化 DP array: DP[0] = nums[0]
4. 確認遍歷順序: i = 1 to n
5. 舉例驗證 DP array: [2,5,1,0,1,2,1,0]
DP[0] = 2, DP[1] = 6, DP[2] = 6, DP[3] = 6, DP[4] = 6, DP[5] = 8, DP[6] = 9, DP[7] = 9
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    bool canJump(vector<int> &nums)
    {
        vector<int> DP(nums.size(), -1);
        DP[0] = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            if (DP[i - 1] >= i)
                DP[i] = max(DP[i - 1], i + nums[i]);
            else
                DP[i] = -1;
        }
        if (DP[nums.size() - 1] >= int(nums.size()) - 1)
            return true;
        else
            return false;
    }
};

int main()
{
    vector<int> nums = {3, 2, 1, 0, 4};
    Solution sol;
    cout << sol.canJump(nums);
}