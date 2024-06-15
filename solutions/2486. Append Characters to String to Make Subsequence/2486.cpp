/*
time complexity : O(n)
tags: Two Pointers, String, Greedy
note: 沿著 s 從第一個字元比到最後一個字元，使用兩個 index 指向當前要比較的 s 與 t 字元，當兩個 index 指導的字元一樣，t 的 index 就往後一格。
最終可以找到 t 中有多少個字元按照先後順序出現在 s 裡頭。
*/

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int appendCharacters(string s, string t) {
        int s_idx, t_idx;
        int s_length = s.length(), t_length = t.length();
        int count = 0;
        for (s_idx = 0, t_idx = 0; s_idx < s_length; s_idx ++)
        {
            if (s[s_idx] == t[t_idx])
            {
                count ++;
                t_idx ++;
            }
        }
        return t_length - count;
    }
};