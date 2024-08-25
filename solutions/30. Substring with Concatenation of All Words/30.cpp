/*
time complexity: O(n)
tags: Hash Table, String, Sliding Window
note: 嫌見註解
*/

class Solution
{
public:
    vector<int> findSubstring(string s, vector<string> &words)
    {
        int wordLen = words[0].size();
        int wordCount = words.size();
        int totalLen = wordLen * wordCount;
        unordered_map<string, int> wordsMap;
        vector<int> ans;

        // 記錄 words 中每個 string 出現的次數
        for (auto &w : words)
        {
            wordsMap[w]++;
        }

        // 遍歷所有可能的起點 offset
        for (int offset = 0; offset < wordLen; offset++)
        {
            unordered_map<string, int> seen;
            int left = offset, right = offset;
            int count = 0;

            // 滑動窗口遍歷整個字串 s
            while (right + wordLen <= s.size())
            {
                string word = s.substr(right, wordLen);
                right += wordLen;

                // 如果該 word 在 wordsMap 中
                if (wordsMap.count(word))
                {
                    seen[word]++;
                    count++;

                    // 當某個 word 出現次數超過要求次數時，移動 left
                    while (seen[word] > wordsMap[word])
                    {
                        string leftWord = s.substr(left, wordLen);
                        seen[leftWord]--;
                        count--;
                        left += wordLen;
                    }

                    // 當所有單詞匹配時，記錄起始位置
                    if (count == wordCount)
                    {
                        ans.push_back(left);
                    }
                }
                else
                {
                    // 否則，重置窗口
                    seen.clear();
                    count = 0;
                    left = right;
                }
            }
        }

        return ans;
    }
};
