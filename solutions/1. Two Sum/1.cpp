/*
time complexity : O(n)
tags: Array, Hash Table
note: 用 Hash Table 存下已經看過的數字作為 key，index 作為 value，當 target - 當前的數字有存在 Table 中就可以直接拿來用
*/

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        unordered_map<int, int> visited;
        for (int i = 0; i < nums.size(); i++)
        {
            int num = nums[i];
            // 若 target - num 已經拜訪過了， visited.cout 會回傳 1 否則回傳 0
            if (visited.count(target - num))
                return {i, visited[target - num]};
            // 紀錄已拜訪過的數字
            visited[num] = i;
        }
        return {};
    }
};

int main()
{
    Solution sol;
    vector<int>nums{3, 2, 4};
    vector<int> Ans = sol.twoSum(nums, 6);
    cout << Ans[0] << " " << Ans[1];
}
