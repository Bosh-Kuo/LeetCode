/*
time complexity: O(n)
tags: Tree, Depth-First Search, Breath-First Search
note: 用 DFS 遍歷每個 children，pass by reference 讓每個 recursion level 共用同個 max
*/

class Solution
{
public:
    void DFS(Node *current, int level, int &max)
    {
        if (current == nullptr)
            return;
        // 判斷該 level 是否為 max
        if (level > max)
            max = level;

        // 對每個 children DFS
        for (Node *node : current->children)
            DFS(node, level + 1, max);
    }

    int maxDepth(Node *root)
    {
        int max = 0, level = 0;
        if (root != nullptr)
            DFS(root, level + 1, max);
        return max;
    }
};