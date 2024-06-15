/*
time complexity : O(n)
tags: Array, Two Pointers
note: 使用 Two Pointers ，當一個指向 0 的位置一個指向非 0 的位置的時候交換兩個元素的數值
*/

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int zeroPointer = 0, nonzeroPointer = 1;
        while (nonzeroPointer < nums.size())
        {                    
            if (nums[zeroPointer] != 0)
                zeroPointer ++;
            else
            {
                if (nums[nonzeroPointer] != 0)
                {
                    int temp = nums[nonzeroPointer];
                    nums[nonzeroPointer] = nums[zeroPointer];
                    nums[zeroPointer] = temp;
                    zeroPointer ++;
                }
            }
            nonzeroPointer ++;
        }
    }
};