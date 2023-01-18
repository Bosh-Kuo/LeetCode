/*
time complexity: O(n)
tags: Array, Math, Two Pointers
note: 原本後 k 個 element 要變成前 k 個 element，前(n-k) 個 element 要變成前 (n-k) 個 element，我們可以讓後 k 的 element 仍留在後 k 個位置
前 (n-k) 個 element 仍留在前 (n-k) 個位置，但反轉這兩個 subarray，最後再反轉整個 array。若 k >= n，則實際上要處理的 k 應該為 k % n
ex: [1,2,3,4,5,6,7,8,9], k = 3: [6,5,4,3,2,1,9,8,7] -> [7,8,9,1,2,3,4,5,6]
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
    void reverse(vector<int> &array, int start, int end)
    {
        while (start < end)
        {
            int temp = array[start];
            array[start] = array[end];
            array[end] = temp;
            start++;
            end--;
        }
    }
    void rotate(vector<int> &nums, int k)
    {
        k = k % nums.size();
        if (k == 0)
            return;
        else
        {
            reverse(nums, 0, nums.size() - k - 1);
            reverse(nums, nums.size() - k, nums.size() - 1);
            reverse(nums, 0, nums.size() - 1);
        }
    }
};