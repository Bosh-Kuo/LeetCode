/*
time complexity: O(n^2)
tags: Math, Dynamic Programming, Tree, Binary Search Tree, Binary Tree
note: n 個 nodes 的 BST 的總數量就是每個 node 當 head 時的 BST 數量的總和
follow DP 問題 5 步驟：
1. 定義 DP array: DP[i] = i 個 nodes 的 BST 總數量
2. 推導遞迴式:
D[i] = sum(DP[j-1] * DP[i-j]), j from 1 to i ，左子樹有 j-1 個 node，右子樹有 i-j 個 node 的所有狀況加總
3. 初始化 DP array: DP[0] = 1,
4. 確認遍歷順序:  i = 1 ~ n
5. 舉例驗證 DP array: n = 4
DP[0] = 1
DP[1] = 1
DP[2] = DP[0]*DP[1] + DP[1]*DP[0] = 2
DP[3] = DP[0]*DP[2] + DP[1]*DP[1] +  DP[2]*DP[0] = 5
DP[4] = DP[0]*DP[3] + DP[1]*DP[2] +  DP[2]*DP[1] + DP[3]*DP[0] = 14
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int numTrees(int n)
    {
        vector<int> DP(n + 1, 0);
        DP[0] = 1;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= i; j++)
            {
                DP[i] += DP[j - 1] * DP[i - j];
            }
        }
        return DP[n];
    }
};