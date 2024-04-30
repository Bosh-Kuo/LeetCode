/*
time complexity: O(n)
tags: Hash Table, String, Sliding Window
note: 建立 hashmap 儲存 p 中每個 char 出現的次數，接著先確認 s 前 p.size() 個 char 是否符合標準。
接下來從 p.size() 出發一次將一個 char 排出/加入 sliding window，並根據目前紀錄的 illegalNum 檢查目前的 sliding window 是否符合標準。
*/

class Solution
{
public:
    vector<int> findAnagrams(string s, string p)
    {
        vector<int> ans;
        if (p.size() > s.size())
            return ans;

        // 建立 hashmap 儲存 p 中每個 char 出現的次數
        unordered_map<char, int> window;
        for (auto &c : p)
            window[c] = window.count(c) ? window[c] + 1 : 1;

        // check first p.size() char in s
        int illegalNum = 0;
        for (int i = 0; i < p.size(); i++)
        {
            char c = s[i];
            if (window.count(c))
            {
                window[c]--;
                if (window[c] < 0)
                    illegalNum++;
            }
            else
                illegalNum++;
        }
        if (illegalNum == 0)
            ans.push_back(0);

        // sliding through s
        for (int i = p.size(); i < s.size(); i++)
        {
            char outChar = s[i - p.size()];
            char inChar = s[i];

            // 處理剛離開 window 的 char
            if (window.count(outChar))
            {
                window[outChar]++;
                if (window[outChar] <= 0)
                    illegalNum--;
            }
            else
                illegalNum--;

            // 處理剛進入 window 的 char
            if (window.count(inChar))
            {
                window[inChar]--;
                if (window[inChar] < 0)
                    illegalNum++;
            }
            else
                illegalNum++;

            if (illegalNum == 0)
                ans.push_back(i - p.size() + 1);
        }
        return ans;
    }
};