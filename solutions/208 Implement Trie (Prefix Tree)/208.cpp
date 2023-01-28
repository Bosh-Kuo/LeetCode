/*
time complexity:
tags: Hash Table, String, Design, Trie
note: 每個 node 都代表一個字母，每個 node 最多可以有 26 個 children，若一個 node 為一個 word 的最後一個字，標示該 node 為 leaf。
ref: https://englishandcoding.pixnet.net/blog/post/29962012-leetcode-%E7%AD%86%E8%A8%98%EF%BC%8D208.-implement-trie-%28prefix-tree%29-%7C-%E4%BB%80%E9%BA%BC
*/

#include <iostream>
#include <string>

using namespace std;

class Trie {
public:
    bool isLeaf;
    Trie *node[26]; // 每個 node 都可以接 26 個字母作為 children
    Trie()
    {
        isLeaf = false;
        for (int i = 0; i < 26; i++)
            this->node[i] = nullptr;
    }

    void insert(string word)
    {
        if (!word.length())
        {
            this->isLeaf = true;
            return;
        }
        if (!this->node[word[0] - 'a'])
            this->node[word[0] - 'a'] = new Trie;
        this->node[word[0] - 'a']->insert(word.substr(1));
    }

    bool search(string word)
    {
        if (!word.length())
        {
            if (this->isLeaf)
                return true;
            else
                return false;
        }
        else
        {
            if (!this->node[word[0] - 'a'])
                return false;
            else
                return this->node[word[0] - 'a']->search(word.substr(1));
        }
    }

    bool startsWith(string prefix)
    {
        if (!prefix.length())
            return true;

        if (!this->node[prefix[0] - 'a'])
            return false;
        else
            return this->node[prefix[0] - 'a']->startsWith(prefix.substr(1));
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */