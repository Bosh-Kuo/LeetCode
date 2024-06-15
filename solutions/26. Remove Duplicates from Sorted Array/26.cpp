/*
time complexity : O(n)
tags: Array, Two Pointers
note: 用 Two Pointer，當第二個 idx 指向的 val 跟第一個 idx 指向的 val 不一樣，第一個 idx 前進一步後，
用當前第二個 idx 指向的 val 取代第一個 idx 指向的 val
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
        int count = 1;
        for (idx1 = 0, idx2 = 0; idx2 < nums.size(); idx2++)
        {
            if (nums[idx1] != nums[idx2])
            {
                idx1 += 1;
                nums[idx1] = nums[idx2];
                count++;
            }
        }
        return count;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {0, 0, 1};
    cout << sol.removeDuplicates(nums) << endl;
    for (auto e : nums)
        cout << e << " ";
}