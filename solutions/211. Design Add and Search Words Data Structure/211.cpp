/*
time complexity: O(n^2)
tags: String, Depth-First Search, Design, Trie
note: 用 Trie 來存所有 word，當遇到 . 的時候，代表 . 可能為當前 node 的任何 child node，因此可以用
DFS 遍歷目前所在 node 的所有 children，搜尋所有可能的結果，當有任一條搜尋路徑有搜尋到，即返回 true
*/

class Trie
{
public:
    bool isEnd = false;
    unordered_map<char, Trie *> childMap;
};

class WordDictionary
{
public:
    Trie *WordsTrie;
    WordDictionary()
    {
        WordsTrie = new Trie();
    }

    void addWord(string word)
    {
        Trie *currentNode = WordsTrie;
        for (char c : word)
        {
            if (currentNode->childMap.count(c) == 0)
                currentNode->childMap[c] = new Trie();
            currentNode = currentNode->childMap[c];
        }
        currentNode->isEnd = true;
    }
    bool search(string word, Trie *currentNode)
    {
        for (int i = 0; i < word.size(); i++)
        {
            char c = word[i];
            if (currentNode->childMap.count(c) == 0)
            {
                if (c != '.')
                    return false;
                else
                {
                    for (auto &it : currentNode->childMap)
                    {
                        bool dfs = search(word.substr(i + 1), it.second);
                        if (dfs)
                            return true;
                    }
                    return false;
                }
            }
            else
                currentNode = currentNode->childMap[c];
        }
        if (currentNode->isEnd)
            return true;
        else
            return false;
    }

    bool search(string word)
    {
        return search(word, WordsTrie);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */