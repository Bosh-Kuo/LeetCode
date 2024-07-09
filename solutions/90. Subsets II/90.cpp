/*
time complexity : O(2^n * n)
tags: Array, Backtracking, Bit Manipulation
note: 在每一層的遞迴中，temp 都是一個沒有與過去重複的子集，在每一層的遞迴中，用 loop 輪流把沒有重複出現過的元素加入 temp 裡，
進入下一層遞迴，再將元素移除
*/

class Solution
{
public:
    void backtrack(int idx, vector<int> &temp, vector<int> &nums,
                   vector<vector<int>> &ans)
    {
        // 將當前的子集加入結果中
        ans.push_back(temp);

        // 在每一層的遞迴中，temp 都是一個沒有與過去重複的子集
        // 該 loop 決定在這層遞迴中是否要把某個元素加入子集，並進入下一層遞迴
        for (int i = idx; i < nums.size(); i++)
        {
            // 如果當前元素與前一個元素相同且不是第一次出現，跳過以避免重複子集
            if (i != idx && nums[i] == nums[i - 1])
                continue;
            temp.push_back(nums[i]);

            // 進行下一層遞歸，處理從下一個索引開始的元素
            backtrack(i + 1, temp, nums, ans);

            // 回退一步，移除當前元素，準備進行下一次迭代
            temp.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {
        vector<vector<int>> ans;
        vector<int> temp;
        sort(nums.begin(), nums.end()); // 先將 nums 排序，方便處理重複元素
        backtrack(0, temp, nums, ans);
        return ans;
    }
};
