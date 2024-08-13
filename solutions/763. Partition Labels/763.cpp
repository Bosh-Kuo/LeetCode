/*
time complexity: O(n)
tags: Hash Table, Two Pointers, String, Greedy
note:
1. 用 hashmap 紀錄 s 中每個字母最後出現的 index
2. 使用 two pointer，將 left 定位於該段的第一個字的位置，right 初始定位於 hashmap[left]，隨著 left 移動 right
3. 當 left == right 則以 left + 1 作為下個段落的開始
*/

class Solution
{
public:
    vector<int> partitionLabels(string s)
    {
        vector<int> ans;
        unordered_map<char, int> lastAppear;
        // 1. 用 hashmap 紀錄 s 中每個字母最後出現的 index
        for (int i = s.size() - 1; i >= 0; i--)
        {
            if (!lastAppear.count(s[i]))
                lastAppear[s[i]] = i;
        }

        // 2. 使用 two pointer，將 left 定位於該段的第一個字的位置，right 初始定位於 hashmap[left]，隨著 left 移動 right
        int left = 0, start = 0, right = lastAppear[s[left]];
        while (left < s.size())
        {
            int right = max(lastAppear[s[left]], right);

            // 3. 當 left == right 則以 left + 1 作為下個段落的開始
            if (left == right)
            {
                ans.push_back(right - start + 1);
                start = left + 1;
            }
            left += 1;
        }
        return ans;
    }
};