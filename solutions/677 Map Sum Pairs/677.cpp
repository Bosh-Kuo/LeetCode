/*
time complexity: O(n)
tags: Hash Table, String, Design, Trie
note: 用 Trie 來存 insert 的 string，便可以從 prefix 的位置往下找所有相同 prefix 的 string
*/
class TrieNode
{
public:
    int val = 0;
    unordered_map<char, TrieNode *> childMap;
    // TriNode* child[26];
};
class MapSum
{
public:
    TrieNode *root;

    MapSum()
    {
        root = new TrieNode();
    }

    void insert(string key, int val)
    {
        TrieNode *current = root;
        // 創建好所有的 child，並走到 key 的最後一個 char 的 node 上
        for (char c : key)
        {
            if (current->childMap.count(c) == 0)
                current->childMap[c] = new TrieNode();
            current = current->childMap[c];
        }
        // 將 val 存於 prefix 所在的 node 上
        current->val = val;
    }

    // 回傳 prefix 所在的 TrieNode
    TrieNode *getPrefixNode(string prefix)
    {
        TrieNode *current = root;
        for (char c : prefix)
        {
            if (current->childMap.count(c) == 0)
                return nullptr;
            else
                current = current->childMap[c];
        }
        return current;
    }

    // 便利所有 cildren nodes，並累加 answer
    void TraverseChildNodes(TrieNode *current, int &answer)
    {
        answer += current->val;
        for (auto childPair = current->childMap.begin(); childPair != current->childMap.end(); ++childPair)
            TraverseChildNodes(childPair->second, answer);
    }

    int sum(string prefix)
    {
        int answer = 0;
        // 取得 prefix 所在的 node
        TrieNode *prefixNode = getPrefixNode(prefix);
        // 如果 prefix 所在的 node 不存在，則回傳 0
        if (prefixNode == nullptr)
            return 0;
        // 從 prefix 所在的 node 開始往下遍歷所有的 child nodes，並累加所有 child 的 val
        else
            TraverseChildNodes(prefixNode, answer);
        return answer;
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */