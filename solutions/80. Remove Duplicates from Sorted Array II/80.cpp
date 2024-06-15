/*
time complexity : O(n)
tags: Array, Two Pointers
note: 用 Two Pointer，當第二個 idx 指向的 val 跟第一個 idx 指向的 val 不一樣，第一個 idx 前進一步後，
用當前第二個 idx 指向的 val 取代第一個 idx 指向的 val，
當第二個 idx 指向的 val 跟第一個 idx 指向的 val 相同，且目前第一個 idx 指向的 val 只出現過一次，同樣地。第一個 idx 前進一步後，
用當前第二個 idx 指向的 val 取代第一個 idx 指向的 val，
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        int idx1, idx2;
        int count = 1, tempCount = 1;
        for (idx1 = 0, idx2 = 1; idx2 < nums.size(); idx2 ++)
        {
            // 兩 idx 指向的 val 相同，且前面尚未有 2個與 idx1 指向的 val 相同的元素
            if(nums[idx1] == nums[idx2] && tempCount < 2)
            {
                tempCount ++;
                count ++;
                idx1 ++;   
                nums[idx1] = nums[idx2];             
            }
            // 兩 idx 指向的 val 不相同
            else if (nums[idx1] != nums[idx2])
            {
                tempCount = 1;
                count ++;
                idx1 ++;
                nums[idx1] = nums[idx2];
            }
        }
        return count;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {1,1,1,2,2,3};
    cout << sol.removeDuplicates(nums) << endl;
    for (auto e : nums)
        cout << e << " ";
}