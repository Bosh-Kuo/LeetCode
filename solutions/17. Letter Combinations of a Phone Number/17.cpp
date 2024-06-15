/*
time complexity :
tags: Hash Table, String Backtracking
note: 用 Hash Table 儲存每個數字對照的字串，透過 backtracking 掃過某個數字下所有可能用來組合的字母，並往下個數字繼續搜尋，
當後面的數字所有的可能都組合過了就移除當前數字的字母，換成下一個字母再繼續往下個數字的位置搜尋。
*/

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    unordered_map<char, string> letters;
    void initLetters()
    {
        letters['2'] = "abc";
        letters['3'] = "def";
        letters['4'] = "ghi";
        letters['5'] = "jkl";
        letters['6'] = "mno";
        letters['7'] = "pqrs";
        letters['8'] = "tuv";
        letters['9'] = "wxyz";
    }

    void backtrack(vector<string> &Ans, string &oneAns, string digits, int index)
    {
        if (oneAns.length() == digits.length())
        {
            // 終止搜尋
            if (digits.length())
                Ans.push_back(oneAns);
            return;
        }

        char number = digits[index];
        for (auto letter : letters[number])
        {
            // 將該位置可能的字母加入到字串最後面
            oneAns += letter;

            // 尋找下個位置要加入的字母
            backtrack(Ans, oneAns, digits, index + 1);

            // 移除目前位置的字母
            oneAns.pop_back();
        }
    }
    vector<string> letterCombinations(string digits)
    {
        initLetters();
        vector<string> Ans;
        string oneAns = "";
        backtrack(Ans, oneAns, digits, 0);
        return Ans;
    }
};

int main()
{
    Solution sol;
    vector<string> letterCombinations = sol.letterCombinations("23");
    for (auto ans: letterCombinations)
        cout << ans << endl;
}