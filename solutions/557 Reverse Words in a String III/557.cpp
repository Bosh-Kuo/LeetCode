/*
time complexity: O(n)
tags: Two Pointers, String
note: 用 Two Pointers，一個指向 word 的開頭，一個指向 word 的結尾，
pointer1 的判斷準則: 前一個位置為 " " 但當前位置不是
pointer2 的判斷準則: 後一個位置為 " " 但當前位置不是
*/

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution
{
public:
    string reverseWords(string s)
    {
        int pointer1 = 0, pointer2 = 0;
        string ans = "";
        for (int i = 0; i < s.length(); i++)
        {
            // 若當前為 ' ' 直接跳過
            if (s[i] == ' ')
            {
                ans.append(" ");
                continue;
            }

            // 判斷該位置是否為 pointer1
            if (i > 0 && s[i - 1] == ' ' && s[i] != ' ')
                pointer1 = i;

            // 判斷該位置是否為 pointer2
            if ((i == s.length() - 1 && s[i] != ' ') || (i != s.length() - 1 && s[i + 1] == ' ' && s[i] != ' '))
            {
                pointer2 = i;
                string sub = s.substr(pointer1, pointer2 - pointer1 + 1);
                reverse(sub.begin(), sub.end());
                ans.append(sub);
            }
        }
        return ans;
    }
};