/*
time complexity: O(n*2^n)
tags: String, Dynamic Programming, Backtracking
note: 使用 backtracking，從 beginIdx = 0 開始，當找到從 beginIdx 開始的某段 substring 為 palindrome，
就將這段 substring 暫存起來，並且遞迴 backtrack 傳入 subString 下個字元作為新的 beginIdx。
當 backtrack 執行結束，將剛剛暫存的 substring 移除，繼續尋找下一段為 palindrome 的 substring
ex:
"aabcbdd"
    "a"->"abcbdd"
        "a"->"bcbdd"
            "b"->"cbdd"
                "c"->"bdd"
                    "b"->"dd"
                        "d"->"d"
                            "d"->""
                    "dd"->""
            "bcb"->"dd"
                "d"->"d"
                    "d"->""
*/

class Solution
{
public:
    bool isPalindrome(string s)
    {
        int left = 0;
        int right = s.length() - 1;
        while (left < right)
        {
            if (s[left] != s[right])
                return false;
            left++;
            right--;
        }
        return true;
    }

    void backtrack(int beginIdx, string &s, vector<string> &temp, vector<vector<string>> &ans)
    {
        if (beginIdx >= s.length())
        {
            ans.push_back(temp);
            return;
        }

        for (int i = beginIdx; i < s.length(); i++)
        {
            if (isPalindrome(s.substr(beginIdx, i - beginIdx + 1)))
            {
                temp.push_back(s.substr(beginIdx, i - beginIdx + 1));
                backtrack(i + 1, s, temp, ans);
                temp.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s)
    {
        vector<vector<string>> ans;
        vector<string> temp;
        backtrack(0, s, temp, ans);
        return ans;
    }
};