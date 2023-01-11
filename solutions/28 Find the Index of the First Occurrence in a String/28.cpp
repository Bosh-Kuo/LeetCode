/*
time complexity: O(n)
tags: Two Pointers, String, String Matching
note: 用 KMP algorithm 來實作 String Matching。
首先，找出的needle 的 prefix array， prefix array 指的是 needle 中每個元素最長的重複 pattern 的 index， ex: [A,B,A,B,A] -> [-1,-1,0,1,2]
接著沿著 haystack 比對，並且透過 prefix array 跳過重複的 pattern
ex: haystack: [C,A,B,A,B,A,B,C,C], needle: [A,B,A,B,C] (prefix array = [-1,-1,0,1,-1])
當 needle[0] 對齊 haystack[1] 開始比對後，needle[4](C) != haystack[5](A)，由於 needle[0~1], needle[2~3]有相同的 pattern，
因此可以直接讓 needle[0] 對齊 haystack[3]，也就是剛剛 needle[2] 的位置上
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
    vector<int> compute_prefix(string &needle)
    {
        int m = needle.size();
        vector<int> pi(m, -1);
        int k = -1;
        for (int q = 1; q < m; q++)
        {
            while(k > -1 && needle[k+1] != needle[q])
                k = pi[k];
            if (needle[k+1] == needle[q])
                k = k + 1;
            pi[q] = k;
        }
        return pi;
    }
    int strStr(string haystack, string needle)
    {
        int n = haystack.size(), m = needle.size();
        vector<int> pi = compute_prefix(needle);
        int q = -1;
        for(int i = 0; i < n; i++)
        {
            while(q > -1 && needle[q+1] != haystack[i])
                q = pi[q];
            if (needle[q+1] == haystack[i])
                q = q+1;
            if (q == m-1)
                return i-m+1;
        }
        return -1;
    }
};

int main()
{
    string haystack = "sadbutsad";
    string needle = "sad";
    Solution sol;
    cout << sol.strStr(haystack, needle);

}