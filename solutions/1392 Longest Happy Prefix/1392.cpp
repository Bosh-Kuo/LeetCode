/*
time complexity : O(n)
tags: String, Rolling Hash, String Matching, Hash Function
note: 用到 KMP algorithm 裡的 prefix function 來計算一個 string 重複的 pattern，看最後一個 character 的 pi 就可以知道最長的 happy prefix
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> compute_prefix(string &s)
    {
        int m = s.size();
        vector<int> pi(m, -1);
        int k = -1;
        for (int q = 1; q < m; q++)
        {
            while (k > -1 && s[k + 1] != s[q])
                k = pi[k];
            if (s[k + 1] == s[q])
                k = k + 1;
            pi[q] = k;
        }
        return pi;
    }
    string longestPrefix(string s)
    {
        vector<int> pi = compute_prefix(s);
        int last_pi = pi[s.length() - 1];
        if (last_pi >= 0)
            return s.substr(0, last_pi + 1);
        else
            return "";
    }
};
