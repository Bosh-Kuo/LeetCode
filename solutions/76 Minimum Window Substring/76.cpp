/*
time complexity: O(m+n)
tags: Hash Table, String, Sliding Window
note: 以當前 subarray 包含了 t 的 characters 的數量是否大等於 t 的長度來判斷當前的 subarray 是否為一個符合條件的 subarray，
若是，則記錄下該 subarray 的長度與尾 index，最終找出最短的 substring
*/

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    string minWindow(string s, string t)
    {
        // 先建立 t 的 hash table
        unordered_map<char, int> t_map;
        for (int i = 0; i < t.length(); i++)
            t_map[t[i]] = t_map.count(t[i]) > 0 ? t_map[t[i]] + 1 : 1;

        // 定義 sliding window 的頭尾
        int pointer1 = 0, pointer2 = 0;

        // 定義最短 subarray 長度與最短 subarray 的頭
        int minLen = 100001, p1 = -1;

        // 定義 s 的 hash table 和 numMatch
        unordered_map<char, int> s_map;
        int numMatch = 0;

        // sliding window
        for (int i = 0; i < s.length(); i++, pointer2++)
        {
            // 計算當前的 s_map match 了幾個 t 的 char （包含重複的 char）
            // 假設 s_map 裡面出現了第二個 'a'，但 t_map 只有一個 'a'，則該 'a'不應該被算進 numMatch
            s_map[s[i]] = s_map.count(s[i]) > 0 ? s_map[s[i]] + 1 : 1;
            if (t_map.count(s[i]) > 0 && s_map[s[i]] <= t_map[s[i]])
                numMatch++;

            // 假設當前的 subarray 為 "DOBECODEBA"， t 為 "ABC" => 則迴圈結束後 subarray 應該變成 "ODEBA"
            while (pointer1 <= pointer2 && numMatch == t.length())
            {
                int length = pointer2 - pointer1 + 1;
                if (length < minLen)
                {
                    minLen = length;
                    p1 = pointer1;
                }

                // 縮小 sliding window
                s_map[s[pointer1]]--;
                // 如果 t = "A", subarray 從 "AAA" 變 "AA"，numMatch 還是 1
                if (t_map.count(s[i]) > 0 && s_map[s[pointer1]] < t_map[s[pointer1]])
                    numMatch--;
                pointer1++;
            }
        }

        if (p1 < 0)
            return "";
        else
            return s.substr(p1, minLen);
    }
};