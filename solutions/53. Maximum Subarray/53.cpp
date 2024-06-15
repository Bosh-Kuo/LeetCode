/*
time complexity: O(nlog(n))
tags: Array, Divide and Conquer, Dynamic Programming
note: 對任意 array 來說，max sub-array 可能在分割點的的左半邊或右半邊或橫跨分割點
-> Divide: 將求一 array 的 max sub-array 的問題分割成求左半與右半與跨分割點三種 max sub-array
-> Conquer: divide 出的三種 max sub-array 中的最大者就是該 array 的 max sub-array
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int maxCrossArray(vector<int> &nums, int left, int mid, int right)
    {
        int leftSum = INT_MIN, rightSum = INT_MIN;
        for (int i = mid, sum = 0; i >= left; i--)
        {
            sum += nums[i];
            if (sum > leftSum)
                leftSum = sum;
        }
        for (int i = mid + 1, sum = 0; i <= right; i++)
        {
            sum += nums[i];
            if (sum > rightSum)
                rightSum = sum;
        }
        return leftSum + rightSum;
    }
    int divideAndConquer(vector<int> &nums, int left, int right)
    {
        // base case
        if (left == right)
            return nums[left];

        // Divide
        int mid = (left + right) / 2;
        int leftMax = divideAndConquer(nums, left, mid);
        int rightMax = divideAndConquer(nums, mid + 1, right);
        int crossMax = maxCrossArray(nums, left, mid, right);

        // Conquer
        return max(leftMax, max(rightMax, crossMax));
    }
    int maxSubArray(vector<int> &nums)
    {
        int left = 0, right = nums.size() - 1;
        return divideAndConquer(nums, left, right);
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {5,4,-1,7,8};
    cout << sol.maxSubArray(nums);
    
}