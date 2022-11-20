/*
time complexity:
tags: String, Dynamic Programming, Backtracking
note: 用 backtrack 遞迴替換每個位置可以放置的括號，當一個位置後面的所有可能都嘗試過，就把該位置換成另一個括弧再往下繼續嘗試所有可能
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
    void addToAns(vector<char> &oneAns, vector<string> &Ans)
    {
        // 複製所有字元到 string
        string stringAns(oneAns.begin(), oneAns.end());

        // 加入 Ans
        Ans.push_back(stringAns);
    }
    void addToOneAns(char bracket, vector<char> &oneAns, int &count_leftBracket, int &count_rightBracket)
    {
        // 放入 bracket
        oneAns.push_back(bracket);

        // 改變 count_leftBracket, count_rightBracket 狀態
        if (bracket == '(')
            count_leftBracket += 1;
        else
            count_rightBracket += 1;
    }
    void removeFromOneAns(vector<char> &oneAns, int &count_leftBracket, int &count_rightBracket)
    {
        // 要移除的 bracket
        char bracket = oneAns.back();

        // 移除最後一個 bracket
        oneAns.pop_back();

        // 改變 count_leftBracket, count_rightBracket 狀態
        if (bracket == '(')
            count_leftBracket -= 1;
        else
            count_rightBracket -= 1;
    }
    bool isValid(char bracket, int count_leftBracket, int count_rightBracket, int n)
    {
        if (bracket == '(')
        {
            if (count_leftBracket < n)
                return true;
            else
                return false;
        }
        else
        {
            if (count_leftBracket > count_rightBracket)
                return true;
            else
                return false;
        }
    }
    void backtrack(vector<char> &oneAns, vector<string> &Ans, int &count_leftBracket, int &count_rightBracket, int n)
    {
        // 當 oneAns 的括弧組數達標就加入 Ans，並停止繼續往下搜尋
        if (oneAns.size() == n * 2)
        {
            addToAns(oneAns, Ans);
            return;
        }

        // 在一個位置上可以填入 "(" or ")"
        vector<char> candidate = {'(', ')'};
        for (char bracket : candidate)
        {
            if (isValid(bracket, count_leftBracket, count_rightBracket, n))
            {
                // 加入 oneAns
                addToOneAns(bracket, oneAns, count_leftBracket, count_rightBracket);

                // 尋找下一個位置要放什麼 bracket 或是否已完成
                backtrack(oneAns, Ans, count_leftBracket, count_rightBracket, n);

                // 移除 oneAns 中，當前位置的 bracket
                removeFromOneAns(oneAns, count_leftBracket, count_rightBracket);
            }
        }
    }
    vector<string> generateParenthesis(int n)
    {
        vector<char> oneAns;
        vector<string> Ans;
        int count_leftBracket = 0, count_rightBracket = 0;
        backtrack(oneAns, Ans, count_leftBracket, count_rightBracket, n);
        return Ans;
    }
};

int main()
{
    Solution sol;
    vector<string> Ans = sol.generateParenthesis(1);
    for (string ans : Ans)
        cout << ans << endl;
}