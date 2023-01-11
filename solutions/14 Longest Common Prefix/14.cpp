/*
time complexity : O(n^2)
tags: String, Trie
note: 定位要比較的 idx，再逐個 string 比較
*/

#include <iostream>
#include <string>
using namespace std;

class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        string Ans = "";
        int idx = 0;

        for (int i = 1; i < strs.size(); i++)
        {
            if (strs[i - 1].size() <= idx || strs[i].size() <= idx)
                return Ans;
            if (strs[i - 1][idx] == strs[i][idx])
            {
                if (i == strs.size() - 1)
                {
                    Ans.push_back(strs[i][idx]);
                    i = 0;
                    idx++;
                }
            }
            else
                return Ans;
        }
        if (strs.size() == 1)
            Ans = strs[0];
        return Ans;
    }
};

int main()
{
}