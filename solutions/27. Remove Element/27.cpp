/*
time complexity : O(n)
tags: Array, Two Pointers
note: 用 Two Pointer，一個指著當前要查看的 idx 一個指著從後面數來第一個不為 val 的 idx，當第一個 idx 後面都沒有任何不為 val 的 element 就可以不用再往下查看了
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int replaceIdx = nums.size() - 1;
        int count = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == val)
            {
                // replaceIdx 指向最後一個不為 val 的位置
                while (replaceIdx > i && nums[replaceIdx] == val)
                    replaceIdx --;
                    
                // 如果 replaceIdx 跟 i 一樣大，代表 i 後面已經沒有位置可以 swap 了
                if (replaceIdx == i)
                    break;

                // swap
                int temp = nums[i];
                nums[i] = nums[replaceIdx];
                nums[replaceIdx] = temp;
            }
                count ++;
        }
        return count;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {0,1,2,2,3,0,4,2};
    int val = 2;
    int ans = sol.removeElement(nums, val);
    cout << ans << endl;
    for (auto e: nums)
    {
        cout << e << " ";
    }
}