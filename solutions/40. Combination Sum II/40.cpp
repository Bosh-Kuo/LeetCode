/*
time complexity: O(2^n)
tags: Array, Backtracking
note: 以 dfs 的概念實踐 backtracking。對於每個 candidate 來說都有「取」 or 「不取」兩種選擇。
取：將數字放入 temp -> recursive 判斷下個 index 取 or 不取 -> 遇到 base conditions 時結束並回傳 void -> pop 掉剛剛放進 temp 的 candidate
不取：略過當前的 candidate 直接進入下個 index。由於會先嘗試「取」的動作，所以如果下個 candidate 與當前的 candidate 相同，會造成重複嘗試相同的 temp 組合
ex: candidates = [1,1,2,2,2,5], index = 2, 取 => temp = {1,1,2} => pop => {1,1}。因 candidate[2+1] == candidate[2+1] 會導致
index = 3 嘗試「取」的時候 temp 又回到 temp = {1,1,3}，因此跳過 index = 3
......
*/

class Solution
{
public:
    void dfs(vector<int> &candidates, int target, int index, vector<vector<int>> &ans, vector<int> &temp)
    {
        // base conditions: take and get the ans
        if (target == 0)
        {
            ans.push_back(temp);
            return;
        }

        if (index >= candidates.size() || target < 0)
            return;

        // take
        temp.push_back(candidates[index]);
        dfs(candidates, target - candidates[index], index + 1, ans, temp);
        temp.pop_back();

        // not take
        // ex: candidates = [1,1,2,2,2,5],  index = 2, temp = {1,1,2} -> {1,1}，
        // 若呼叫 dfs(candidates, target, index+1, ans, temp); 相當於讓 temp 再回到 {1,1,2} 的狀態
        while (index < candidates.size() - 1 && candidates[index] == candidates[index + 1])
            index++;
        dfs(candidates, target, index + 1, ans, temp);
    }
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        vector<vector<int>> ans;
        vector<int> temp;
        sort(candidates.begin(), candidates.end());
        dfs(candidates, target, 0, ans, temp);
        return ans;
    }
};