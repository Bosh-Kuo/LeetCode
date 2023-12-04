/*
time complexity: O(n)
tags: Array, Hash Table, String, Trie
note: 用 Trie 來存 dictionary，接著遍歷 sentence，當該字元不為 '' 且為 Trie 中的某個 child node，
令 abandon = true，直到遇到 '' 再令 abandon = false，當 abandon 為 true 時，直接跳過該字元
*/
class TrieNode
{
public:
    bool isRoot;
    unordered_map<char, TrieNode *> childMap;
    TrieNode()
    {
        this->isRoot = false;
    }
};

class Solution
{
public:
    TrieNode *dictionaryTrie;
    void insertWordsToTrie(string word)
    {
        TrieNode *Node = dictionaryTrie;
        for (auto c : word)
        {
            // 若該 Node 沒有這個字母的 child Node，則將該字母加入該 Node 的 childMap
            if (Node->childMap.count(c) == 0)
                Node->childMap[c] = new TrieNode();

            // 往該字母的 child Node 走
            Node = Node->childMap[c];
        }
        // 走到 word 的最後一個字母後，標記該 Node 為一個 root word 的結尾
        Node->isRoot = true;
    }
    string replaceWords(vector<string> &dictionary, string sentence)
    {
        // 1. 建立 dictionary Trie
        dictionaryTrie = new TrieNode();
        TrieNode *currentNode = dictionaryTrie;
        for (auto word : dictionary)
            insertWordsToTrie(word);

        // 2. 遍歷 sentence
        // 2.1 當該字元不為 '' 且為 Trie 中的某個 child node，令 abandon = true，直到遇到 '' 再令 abandon = false
        string answer = "";
        bool abandon = false, haveToCheckDictionaryTrie = true;
        for (auto c : sentence)
        {
            if (c == ' ')
            {
                answer += c;
                abandon = false;
                haveToCheckDictionaryTrie = true;
                currentNode = dictionaryTrie;
            }
            else
            {
                if (abandon == false)
                {
                    // 不丟棄該 char
                    answer += c;

                    if (haveToCheckDictionaryTrie && currentNode->childMap.count(c) != 0)
                    {
                        // 走到該 Node 上
                        currentNode = currentNode->childMap[c];

                        // 若該 Node 為找到 root word 的最後一個字母，令 abondon 為 true 且 currentNode 回到 dictionaryTrie 起點
                        if (currentNode->isRoot)
                        {
                            abandon = true;
                            currentNode = dictionaryTrie;
                        }
                    }
                    else
                        haveToCheckDictionaryTrie = false;
                }
            }
        }
        return answer;
    }
};