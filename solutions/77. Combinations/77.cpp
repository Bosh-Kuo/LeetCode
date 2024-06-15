/*
time complexity: 
tags: Backtracking
note: 用 backtracking 遞迴訓找可以加入組合的數字。當一個數字可以加入組合當中，下一次搜尋就從此處開始。
當組合中的一個數後面接的所有可能組合都試過了，就將此數換成別的數，繼續往下搜尋。
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void backtrack(vector<vector<int>> &Ans, vector<int> &oneAns, int n, int k, int baseNumber)
    {
        // 若組合已經達到要求的長度則加入 Ans 並且停止繼續往下搜尋
        if (oneAns.size() == k)
        {
            Ans.push_back(oneAns);
            return;
        }
        
        // 把可以放入的數字掃過一輪
        // baseNumber 為組合中的最後一個數字，要加入的數字一定要比 baseNumber 還大
        for (int i = baseNumber + 1; i <= n; i++)
        {
            // 將該數字加入組合
            oneAns.push_back(i);
            
            // 尋找下一個可以加入組合的數字
            backtrack(Ans, oneAns, n, k, i);
            
            // backtracking: 後面的數字組合都掃過了，移除當前位置的數字換成下一個數字繼續往下找
            oneAns.pop_back();
        }
        
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> Ans;
        vector<int> oneAns;
        backtrack(Ans, oneAns, n, k, 0);
        return Ans;
    }
};