/*
time complexity : O(n)
tags: Array, Binary Search, Sliding Window, Prefix Sum
note: 把題目轉換成找出最多包含 k 個 0 的最大 sub array。當左右邊界內的 0 的數量大於 k 時，左邊界開始向右走，直到滿足邊界內 0 數量不大於 k 為止。
在左邊界往右走的時間又邊界仍然可以一起往右繼續走，因為若答案在後面，後面的答案勢必會大於現在邊界區間的大小，若答案不在後面，現在的邊界區間就是最大的區間。

*/

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int leftIdx = 0;
        int maxConsecutive = 0;
        int countZero = 0;
        
        for (int rightIdx = 0; rightIdx < nums.size(); rightIdx++)
        {
            if (nums[rightIdx] == 0)
                countZero += 1;
            
            // 當左右區間內的 0 大於 k 了，左邊界就需要一起移動了，否則只需要移動右邊界，此時區間大小固定在當前的 maxConsecutive
            if (countZero > k)
            {
                if (nums[leftIdx]==0)
                    countZero -= 1;
                leftIdx += 1;
            }
            
            // 只有當區間內的 0 數量小於等於 k 才能計算 maxConsecutive
            if (countZero <= k)
                maxConsecutive = max(rightIdx - leftIdx + 1, maxConsecutive);
        }
        return maxConsecutive;
         
    }
};
