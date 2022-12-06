/*
time complexity: O(n)
tags: Array, Two Pointers, Sorting
note: 用 Two Pointers 維持一者指向奇數，一者指向偶數，當期數指標超過偶數指標即可終止
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int idxOddPointer = 0, idxEvenPointer = nums.size() - 1;
        while(idxOddPointer < idxEvenPointer)
        {
            while(nums[idxOddPointer] % 2 == 0 && idxOddPointer < nums.size() - 1)
                idxOddPointer ++;
            while(nums[idxEvenPointer] % 2 != 0 && idxEvenPointer > 0)
                idxEvenPointer --;
            if (idxOddPointer < idxEvenPointer)
            {
                int temp = nums[idxOddPointer];
                nums[idxOddPointer] = nums[idxEvenPointer];
                nums[idxEvenPointer] = temp;
            }
        }
        return nums;
    }
};