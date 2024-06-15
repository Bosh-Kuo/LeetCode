/*
time complexity:
tags: Array, String, Backtracking, Trie, Matrix
note: 先用 Trie 來記錄所有的 words，接著逐一從 board[i][j] 以 dfs back tracking，
如果走訪到的位置已經走訪過，或者是不在 Trie 內，則直接返回。
如果走訪到的位置有在 Trie 內，且剛好是一個 word 的結尾，則把該 word 加入 answer，並且將 Trie 中該 node 中存的 word 記號移除，避免重複搜尋到同的 word
*/

class Trie
{
public:
    unordered_map<char, Trie *> childMap;
    bool isWordEnd = false;
    string word = "";
};

class Solution
{
public:
    vector<string> findWords(vector<vector<char>> &board, vector<string> &words)
    {
        Trie *root = buildTrie(words);
        vector<string> answer;
        for (int i = 0; i < board.size(); i++)
            for (int j = 0; j < board[0].size(); j++)
                dfs(board, i, j, root, answer);
        return answer;
    }

    Trie *buildTrie(vector<string> &words)
    {
        Trie *root = new Trie();
        for (string word : words)
        {
            Trie *current = root;
            for (char c : word)
            {
                if (current->childMap.count(c) == 0)
                    current->childMap[c] = new Trie();
                current = current->childMap[c];
            }
            current->isWordEnd = true;
            current->word = word;
        }
        return root;
    }
    void dfs(vector<vector<char>> &board, int i, int j, Trie *current, vector<string> &answer)
    {
        char c = board[i][j];
        if (c == '#' || current->childMap.count(c) == 0)
            return;
        current = current->childMap[c];
        if (current->isWordEnd)
        {
            answer.push_back(current->word);
            // 避免重複添加
            current->isWordEnd = false;
            current->word = "";
        }

        // back tracking: 在原處留下記號，表示已搜尋過該位置
        board[i][j] = '#';
        if (i > 0)
            dfs(board, i - 1, j, current, answer); // 上
        if (i < board.size() - 1)
            dfs(board, i + 1, j, current, answer); // 下
        if (j > 0)
            dfs(board, i, j - 1, current, answer); // 左
        if (j < board[0].size() - 1)
            dfs(board, i, j + 1, current, answer); // 右
        // back tracking: 還原該位置本來的字元
        board[i][j] = c;
    }
};