/*
time complexity: O(n^2) or O(n)
tags: String, Dynamic Programming
note:
solution 1: Expand Around Center
先將原字串處理成每個字符間隔一個特殊符號 #， ex: abacaba => #a#b#a#c#a#b#a#
#a#a#a#a#
計算 i = 0 to i = 2n 做為中心的最大回文半徑，存於 P[i]，並且紀錄當前有最大回文長度的 index i 與最大回文半徑 P[i]

#c#a#b#b#a#
solution 2: Manacher's Algorithm
參考： https://josephjsf2.github.io/data/structure/and/algorithm/2020/10/10/manacher-algorithm.html
*/
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) 
    {
        // Preprocessing
        string t = "#";
        for (auto c : s)
        {
            t += c;
            t += "#";
        }

        int P[t.length()];
        fill(P, P + t.length(), 0);

        // Iteration
        int maxLen = 1, startIdx = 0;
        for (int i = 0; i < t.length(); i++)
        {
            int left = i, right = i;
            while (left >= 0 && right < t.length())
            {
                if (t[left] == t[right])
                {
                    int length = right - left + 1;
                    if (length > maxLen)
                    {
                        maxLen = length;
                        startIdx = left;
                    }
                    left--;
                    right++;
                }
                else
                    break;        
            }            
        }
        return s.substr(startIdx / 2, maxLen / 2);    
    }
};