/*
time complexity: O(n)
tags: Hash Table, String, Breadth-First Search
note:
1. 先將 wordList 裝進 hash set
2. 用 BFS 在每個 iteration 找出下一個 iteration 要搜尋的 transformable word，並裝進 queue 裡
3. 當 queue 尚未清空就持續搜尋，每當一個 word 被搜尋過，就將其從 hash set 中移除，當遇到 end word 時直接回傳當前的 iteration 數
4. 若 wordList 所有字都被搜尋過仍沒有搜尋到 endWord，回傳 0
*/

class Solution
{
public:
    int ladderLength(string beginWord, string endWord, vector<string> &wordList)
    {
        // 先將 wordList 裝進 hash set
        // 用 BFS 在每個 iteration 找出下一個 iteration 要搜尋的 transformable word
        // 每當一個 word 被搜尋過，就將其從 hash set 中移除
        // 當遇到 end word 時直接回傳當前的 iteration 數
        // 若 wordList 所有字都被搜尋過仍沒有搜尋到 endWord，回傳 0
        unordered_set<string> dict(wordList.begin(), wordList.end());
        queue<string> pendingWord;
        pendingWord.push(beginWord);

        int iteration = 1;
        while (!pendingWord.empty())
        {
            int numOfPending = pendingWord.size();
            for (int i = 0; i < numOfPending; i++)
            {
                string word = pendingWord.front();
                pendingWord.pop();
                dict.erase(word);
                if (word == endWord)
                    return iteration;

                // 尋找 transformable word
                for (int j = 0; j < word.size(); j++)
                {
                    char c = word[j];
                    // 搜尋可能的 transformable word
                    for (int k = 0; k < 26; k++)
                    {
                        word[j] = 'a' + k;
                        if (dict.count(word))
                            pendingWord.push(word);
                    }
                    word[j] = c; // 恢復原樣
                }
            }
            iteration++;
        }
        return 0;
    }
};