/*
time complexity: O(n)
tags: String, Dynamic Programming, Stack, Greedy
note: * 的為萬能符號的作用，可以用於抵銷 ( or ) 也可以代表無意義的 ""
1. 使用兩個 stack 儲存 ( 與 * 以及他們所在的 index。首先遍歷 s，優先以 ( 抵銷 )，若最終尚有未抵銷的 ) 直接回傳 false
2. 抵銷完 ) 後剩下 ( 或 *，若 ( 總數大於 * 直接回傳 false
3. 遍歷 * stack，並且確保 * 在 ( 後面才能抵銷
4. 若 * ( 抵銷完後還剩餘 ( 則回傳 false
*/

class Solution
{
public:
    bool checkValidString(string s)
    {
        stack<pair<char, int>> leftStack;
        stack<pair<char, int>> starStack;
        // 1. 遍歷 s，遇到 * or ( 先用 stack 暫存起來
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '*')
                starStack.push({s[i], i});
            else if (s[i] == '(')
            {
                leftStack.push({s[i], i});
            }
            else
            {
                // 遇到 ) 優先以 leftStack 的 ( 抵銷
                if (!leftStack.empty())
                {
                    leftStack.pop();
                    continue;
                    // 若 leftStack 為空，則用 * 抵銷
                }
                else if (!starStack.empty())
                {
                    starStack.pop();
                    // 若前面沒有 ( 或 * 可抵銷，直接回傳 false
                }
                else
                {
                    return false;
                }
            }
        }

        // 2. 能走到這裡代表只剩下 ( 或 *
        // 剩下的 ( 多於 * => 回傳 false
        if (leftStack.size() > starStack.size())
            return false;

        // 3. 確保剩下的 ( 在 * 之前
        while (!leftStack.empty() && !starStack.empty())
        {
            if (starStack.top().second > leftStack.top().second)
            {
                starStack.pop();
                leftStack.pop();
            }
            else
            {
                return false;
            }
        }
        // 最後確保沒有剩下的 (
        return leftStack.empty();
    }
};
