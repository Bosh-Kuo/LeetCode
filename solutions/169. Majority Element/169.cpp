/**
time complexity: O(n)
tags: Array, Hash Table, Divide and Conquer, Sorting, Counting
note: 用 candidate 紀錄當前最常遇到的數，當遇到非 candidate 的數時 count -= 1，當 count 歸零後重新指定 candidate
*/

class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        int count = 0;
        int candidate;
        for (int num : nums)
        {
            if (count == 0)
                candidate = num;

            if (candidate == num)
                count++;
            else
                count--;
        }
        return candidate;
    }
};