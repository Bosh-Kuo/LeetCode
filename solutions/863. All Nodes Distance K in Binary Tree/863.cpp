/*
time complexity: O(n)
tags: Hash Table, Tree, Depth-First Search, Breadth-First Search, Binary Tree
note: 概念為從 target 開始向根部方向以及向 children 方向各自 DFS，且不重複走訪已經遍歷過的節點。
因此需要使用 hash map 紀錄每個節點的 parent
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
public:
    void makeParentMap(TreeNode *currentNode, TreeNode *parentNode, unordered_map<TreeNode *, TreeNode *> &parentMap)
    {
        if (currentNode == nullptr)
            return;
        parentMap[currentNode] = parentNode;
        makeParentMap(currentNode->left, currentNode, parentMap);
        makeParentMap(currentNode->right, currentNode, parentMap);
    }
    void dfs(TreeNode *current, int k, unordered_map<TreeNode *, TreeNode *> &parentMap, unordered_set<TreeNode *> &visited, vector<int> &ans)
    {
        // 若走到盡頭或已經訪問過該節點，則結束
        if (current == nullptr || visited.count(current) > 0)
            return;

        visited.insert(current);
        if (k == 0)
        {
            ans.push_back(current->val);
            return;
        }

        // 向下 dfs
        dfs(current->left, k - 1, parentMap, visited, ans);
        dfs(current->right, k - 1, parentMap, visited, ans);
        // 向上 dfs
        dfs(parentMap[current], k - 1, parentMap, visited, ans);
    }
    vector<int> distanceK(TreeNode *root, TreeNode *target, int k)
    {
        vector<int> ans;
        unordered_map<TreeNode *, TreeNode *> parentMap; // 紀錄每個 node 的 parent
        unordered_set<TreeNode *> visited;               // 紀錄已經遍歷過的 nodes

        // 建立 parentMap
        makeParentMap(root, nullptr, parentMap);
        // 從 target 開始向下、向上 dfs
        dfs(target, k, parentMap, visited, ans);
        return ans;
    }
};