/*
time complexity: O(n)
tags: Array, Dynamic Programming
note:
1. 定義 DP table：
若 nums[i] != 0：
    maxSubArrayProduct 為到 i 為止的 subarry 的最大連續乘機，
    minSubArrayProduct 為到 i 為止的 subarry 的最小連續乘機，
若 nums[i] == 0:
    maxSubArrayProduct, minSubArrayProduct 皆回歸到 0
2. 定義推導公式：
若 nums[i] < 0：
    maxSubArrayProduct = max(minSubArrayProduct * num[i], num[i](num[i-1]為0時))
    minSubArrayProduct = min(maxSubArrayProduct * num[i], num[i](num[i-1]為0時))
若 nums[i] >= 0：
    maxSubArrayProduct = max(maxSubArrayProduct * num[i], num[i](num[i-1]為0時))
    minSubArrayProduct = min(minSubArrayProduct * num[i], num[i](num[i-1]為0時))
*/

class Solution
{
public:
    int maxProduct(vector<int> &nums)
    {
        int maxSubArrayProduct = 1;
        int minSubArrayProduct = 1;
        int answer = INT_MIN;

        for (int i = 0; i < nums.size(); i++)
        {
            // 當 nums[i-1] == 0，maxSubArrayProduct, minSubArrayProduct 都為 0
            if (nums[i] < 0)
                swap(maxSubArrayProduct, minSubArrayProduct);
            maxSubArrayProduct = max({maxSubArrayProduct * nums[i], nums[i]});
            minSubArrayProduct = min({minSubArrayProduct * nums[i], nums[i]});
            answer = max(maxSubArrayProduct, answer);
        }
        return answer;
    }
};