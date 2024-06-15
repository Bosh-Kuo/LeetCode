/*
time complexity: O(2^n)
tags: Array, Backtracking, Bit Manipulation
note: 從一個空陣列開始，每次遞歸時選擇是否將當前元素加入 temp，遍歷所有 index，
每個 index 都有加入或不加入到 temp 中的選擇，並在每個 index 都確保 temp 回到該進入 index 的狀態。
達到終止條件時將當前 temp 加入到 answer
*/

class Solution
{
public:
    vector<vector<int>> answer;
    void backtracking(vector<int> &temp, vector<int> &nums, int index)
    {
        // 若 index 到底了，answer.push(temp)
        if (index == nums.size())
        {
            answer.push_back(temp);
            return;
        }
        // temp 不取 nums[index] 直接往下走
        backtracking(temp, nums, index + 1);

        // temp 取 nums[index] 後往下走
        temp.push_back(nums[index]);
        backtracking(temp, nums, index + 1);

        // 回到 temp 尚未取 nums[index] 的狀態
        temp.pop_back();
    }
    vector<vector<int>> subsets(vector<int> &nums)
    {
        vector<int> temp = {};
        backtracking(temp, nums, 0);
        return answer;
    }
};