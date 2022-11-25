/*
time complexity : O(n)
tags: Array, Stack, Monotonic Stack
note:
計算以某元素為長方形高度的情況下能為出的最大長方形面積，其算法為找出該元素左右兩端第一個比該元素 height 還小的 index 做為長方形的左右邊界。
舉例來說 [2,3,4,5,4,3,2]:
1. 對於 index = 3 (height  = 5) 來說，
左：index = 2 (height = 4)，右：index = 4 (height = 4) => 面積  = 5 * (4-2-1) = 5
2. 對於 index = 4 (height  = 4) 來說，
左：index = 1 (height = 3)，右：index = 5 (height = 3) => 面積  = 4 * (5-1-1) = 12

用 monotonic stack 儲存比當前元素高度還低的 index，若當前元素比 stack top 還低，代表當前元素的 index 就成為了右邊界，而 stack top 
在 stack 中前一個元素的 index 就是左邊界，若 stack top 已經為 stack 中最後一個元素，則左邊界則為 -1，依序對 stack pop，直到 stack top 的值小於等於當前的元素再往下個元素走。
reference: https://leetcode.com/problems/largest-rectangle-in-histogram/discuss/1727776/JavaC%2B%2B-Explanation-going-from-Brute-to-Optimal-Approach
*/

#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
using namespace std;

class Solution
{
public:
    
    int largestRectangleArea(vector<int> &heights)
    {
        stack<int> monotonicStack;
        int maxArea = 0;
        int n = heights.size();
        heights.push_back(0);

        for (int i = 0; i <= n; i++)
        {
            int currHeight = heights[i];
            while (!monotonicStack.empty() && currHeight < heights[monotonicStack.top()])
            {
                int rightIndex = i;
                int heightLargest = heights[monotonicStack.top()];
                monotonicStack.pop();

                int width = monotonicStack.empty() ? rightIndex : rightIndex - monotonicStack.top() - 1;  // 若 stack top 已經是 stack 中最後一個元素了，代表寬度為右邊界到 0
                maxArea = max(width * heightLargest, maxArea);
            }
            monotonicStack.push(i);
        }
        return maxArea;
    }
};

int main()
{
    Solution sol;
    vector<int> heights = {2,1,5,6,2,3};
    cout << sol.largestRectangleArea(heights);
}