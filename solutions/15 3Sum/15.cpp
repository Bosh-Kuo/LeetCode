/*
time complexity : O(n^2)
tags: Array, Two Pointers, Sorting
note: 先將 Array 從小到大排序好，以 Loop 取 nums[i] 作為固定值，取 i 右側最近與最遠的 element 作為 Two Pointers 起點
觀察 nums[i] + left + right:
= 0 則加入答案組中
> 0 : right pointer 向左走
< 0 : left pointer 向右走
*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        vector<vector<int>> Ans;
        // 先從小排到大
        sort(nums.begin(), nums.end());

        // 固定一個 element 用 Two Pointers 來尋找另外兩個合適的 element
        for (int i = 0; i < nums.size(); i++)
        {
            // 跟前面一個 element 重複時就跳過
            if (i > 0 && nums[i] == nums[i - 1])
                continue;

            // 當最前面的 element 都大於 0 了，後面的 element 肯定也會大於 0
            if (nums[i] > 0)
                break;

            // Two pointers， 一個從小往大走，一個從大往小走
            int low_idx = i + 1, high_idx = nums.size() - 1;
            while (low_idx < high_idx)
            {
                if (nums[i] + nums[low_idx] + nums[high_idx] < 0)
                    low_idx++;
                else if (nums[i] + nums[low_idx] + nums[high_idx] > 0)
                    high_idx--;
                else
                {
                    // 兩個 index 指到的 element 若跟前一步的重複則不採計
                    if ((low_idx > i + 1 && nums[low_idx] == nums[low_idx - 1]) || (high_idx < nums.size() - 1 && nums[high_idx] == nums[high_idx + 1]))
                    {
                        low_idx++;
                        high_idx--;
                    }
                    else
                    {
                        Ans.push_back({nums[i], nums[low_idx], nums[high_idx]});
                        low_idx++;
                        high_idx--;
                    }
                }
            }
        }

        return Ans;
    }
};

int main()
{
}