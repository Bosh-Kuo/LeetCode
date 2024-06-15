/*
time complexity: O(n)
tags: Two Pointers, String
note: 當前的 character 為 ' ' 且 pointer1, pointer2 都指向 ' ' 時， pointer1, pointer2 繼續向前不做斷詞
當前 當前的 character 為 ' ' 且 pointer1, pointer2 皆不指向 ' ' 時進行斷詞。
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
    string reverseWords(string s)
    {
        string Ans = "";
        int pointer1 = 0, pointer2 = 0;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == ' ')
            {
                if (s[pointer1] != ' ' && s[pointer2] != ' ')
                {
                    string front = s.substr(pointer1, pointer2 - pointer1 + 1);
                    Ans = Ans.length() == 0 ? front : front + " " + Ans;
                }
                pointer1 = i;
                pointer2 = i;
            }
            else
            {
                pointer2 = i;
                if (i > 0 && s[i - 1] == ' ')
                    pointer1 = i;
                if (i == s.length() - 1)
                {
                    string front = s.substr(pointer1, pointer2 - pointer1 + 1);
                    Ans = Ans.length() == 0 ? front : front + " " + Ans;
                }
            }
        }
        return Ans;
    }
};

int main()
{
    string s = "the sky is blue";
    Solution sol;
    cout << sol.reverseWords(s);
}