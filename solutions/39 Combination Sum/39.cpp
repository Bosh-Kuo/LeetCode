/*
time complexity:
tags: Array, Backtracking
note: 以 DFS 的遍歷 N-tree 的概念去想，當走到該 level 的 current sum 還沒到達 target，就再往下走一個 level，並且不使用 current index 以前 candidate，
若往下個 level 走後達到終止條件，則往回走一個 level 並且將 current index 換成下一個
ex: candidate = [2,1,4,5] => target = 4
[2] -> [2,2](達終止條件)
    -> [2,1] -> [2,1,1](達終止條件)
             -> [2,1,4](達終止條件)
             -> [2,1,5](達終止條件)
    -> [2,4](達終止條件)
    -> [2,5](達終止條件)
[1] -> [1,1] -> [1,1,1] -> [1,1,1,1](達終止條件)
                        -> [1,1,1,4](達終止條件)
                        -> [1,1,1,5](達終止條件)
             -> [1,1,4](達終止條件)
             -> [1,1,5](達終止條件)
......
*/

class Solution
{
public:
    void backtracking(vector<vector<int>> &answers, vector<int> &current, vector<int> &candidates, int &target, int currentSum, int currentIdx)
    {
        // 終止條件
        if (currentSum == target)
        {
            answers.push_back(current);
            return;
        }
        if (currentIdx >= candidates.size() || currentSum > target)
            return;

        // 在 current 多加一個 element, ex: [2,2] -> [2,2,2]
        current.push_back(candidates[currentIdx]);
        // 往下走一層(current 長度 + 1, 且 currentSum 已加上新的 element)
        backtracking(answers, current, candidates, target, currentSum + candidates[currentIdx], currentIdx);
        // 無論在該位置加上該 element 有什麼衍生結果，把該 element 拔掉，準備換成下一個 element, ex: [2,2,2] -> [2,2]
        current.pop_back();

        // 如果 currentIdx 還沒輪到最後一個 candidate， 就把 currentIdx 換成 currentIdx + 1
        if (currentIdx + 1 < candidates.size())
            backtracking(answers, current, candidates, target, currentSum, currentIdx + 1);
    }
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        vector<vector<int>> answers;
        vector<int> current;
        backtracking(answers, current, candidates, target, 0, 0);
        return answers;
    }
};
