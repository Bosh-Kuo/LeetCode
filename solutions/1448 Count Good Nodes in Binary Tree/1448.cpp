/*
time complexity: O(n)
tags: Tree, Depth-First Search, Breadth-First Search, Binary Tree
note: 使用 dfs，將 path 上遇到的最大值往下傳遞
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    int dfs(TreeNode *root, int pathMax)
    {
        if (root == nullptr)
            return 0;

        if (root->val >= pathMax)
            return 1 + dfs(root->left, root->val) + dfs(root->right, root->val);
        else
            return dfs(root->left, pathMax) + dfs(root->right, pathMax);
    }

    int goodNodes(TreeNode *root)
    {
        return dfs(root, root->val);
    }
};