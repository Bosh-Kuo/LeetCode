/*
time complexity: O(n)
tags: Array, Two Pointers, Dynamic Programming, Stack, Monotonic Stack
note: // 記錄下每個 index 往前往後看到的最大值，取其中較小值減掉 index 的高度就是該位置可以存的水量
*/

class Solution
{
public:
    int trap(vector<int> &height)
    {
        // 該 index 可以存多少水取決於該 index 往前往後看到的最大值
        int length = height.size();
        vector<int> fwd(length), bwd(length);
        int ans = 0;
        int maxHeight = 0;
        for (int i = 0; i < length; i++)
        {
            maxHeight = max(maxHeight, height[i]);
            bwd[i] = maxHeight;
        }

        maxHeight = 0;
        for (int i = length - 1; i >= 0; i--)
        {
            maxHeight = max(maxHeight, height[i]);
            fwd[i] = maxHeight;
        }

        for (int i = 0; i < length; i++)
        {
            ans += min(fwd[i], bwd[i]) - height[i];
        }
        return ans;
    }
};