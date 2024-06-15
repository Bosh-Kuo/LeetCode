/*
time complexity: O(n)
tags: Hash Table, String, Dynamic Programming, Trie, Memorization
note: 若由人來判斷，會直覺的將字串拆分，並且看拆分的字串是否可以由 wordDict 拼出，
舉例來說，判斷 "catsandog" 我們發現 "dog" 在 wordDict 裏面，便會檢查 "catsan" 是否可以用 wordDict 來拼出
follow DP 問題 5 步驟：
1. 定義 DP array: DP[i] = 從 index 0 到 index i 前的子字串是否可以用 wordDict 來拼出，
2. 推導遞迴式: 若 d[j] = true 且 s.substr(j, i - j) 出現在 wordDict 則 d[i] = true
3. 初始化 DP array: d[0] = true
4. 確認遍歷順序:  i = 0 to n
5. 舉例驗證 DP array: s = "catsandog", wordDict = ["cats","dog","sand","and","cat"]
dp[0] = true,
dp[1] to dp[2] = fasle
dp[3] = true
dp[4] = true
dp[5] to dp[6] = false
dp[7] = true
dp[8] = false
dp[9] = false
ref; https://leetcode.com/problems/word-break/solutions/127450/word-break/
*/

#include <iostream>
#include <unordered_set>
#include <vector>
#include <string>

using namespace std;

class Solution
{
public:
    bool wordBreak(string s, vector<string> &wordDict)
    {
        unordered_set<string> word_set(wordDict.begin(), wordDict.end());
        vector<bool> dp(s.length() + 1);
        dp[0] = true;

        for (int i = 1; i <= s.length(); i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (dp[j] and word_set.count(s.substr(j, i - j)))
                {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[s.length()];
    }
};