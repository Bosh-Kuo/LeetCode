/*
time complexity :
tags: Array, Backtracking
note: 用 backtrack 來找家別可能解中每個為可以放置什麼數，若可以放置某個數就往下個位置搜尋，當漚面的位置所有可能組合都放置過了，
就更改當前的位置繼續向後面的位置搜尋
*/


#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    void backtrack(vector<int> &nums, vector<vector<int>> &Ans, vector<int> &oneAns, vector<int> &indexMap, int n)
    {
        // 當 oneAns 答案長度達到 n 就加到 Ans 裡並停止繼續向下搜尋
        if (oneAns.size() == n)
        {
            Ans.push_back(oneAns);
            return;
        }

        // 全部可能掃過一輪
        for (int i = 0; i < n; i++)
        {
            if (indexMap[i] == 0)
            {
                // 加入 oneAns，並在 indexMap 註記該數已被加入 oneAns
                oneAns.push_back(nums[i]);
                indexMap[i] = 1;

                // 搜尋 oneAns 下個位置要填入什麼數值
                backtrack(nums, Ans, oneAns, indexMap, n);

                // backtrack: 移除 indexMap 中該數質的註記以及 oneAns 中的數
                oneAns.pop_back();
                indexMap[i] = 0;
            }
        }
    }
    vector<vector<int>> permute(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> indexMap(n, 0); // 用 indexMap 紀錄目前哪幾個 index 位置上的數值已被加入 oneAns
        vector<vector<int>> Ans;
        vector<int> oneAns;
        backtrack(nums, Ans, oneAns, indexMap, n);
        return Ans;
    }
};

int main()
{
    vector<int> nums{1, 2, 3};
    Solution sol;
    vector<vector<int>> Ans = sol.permute(nums);
    for (vector<int> vec: Ans)
    {
        for(int i: vec)
            cout << i << " ";
        cout << endl;
    } 
}