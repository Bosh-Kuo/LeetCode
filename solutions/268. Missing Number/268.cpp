/*
time complexity: O(n)
tags: Array, Hash Table, Math, Binary Search, Bit Manipulation, Sorting
note:
*/

class Solution
{
public:
    int missingNumber(vector<int> &nums)
    {
        int n = nums.size();
        int sum = n * (n + 1) / 2;
        int accumulation = 0;
        for (int number : nums)
            accumulation += number;
        return sum - accumulation;
    }
};