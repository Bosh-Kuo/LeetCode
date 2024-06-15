/*
time complexity: O(n)
tags: Tree, Depth-First Search, Binary Tree
note: 用 DFS 取得每個節點的 leftHeight, rightHeight，只要兩者相差超過 1 ，直接回傳 -1，最終只要 return 非 -1 及為 balanced binary tree
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
    int dfsHeight(TreeNode *root)
    {
        if (root == nullptr)
            return 0;

        int leftHeight = dfsHeight(root->left);
        if (leftHeight == -1)
            return -1;
        int rightHeight = dfsHeight(root->right);
        if (rightHeight == -1)
            return -1;

        if (abs(leftHeight - rightHeight) > 1)
            return -1;
        else
            return max(leftHeight, rightHeight) + 1;
    }

    bool isBalanced(TreeNode *root)
    {
        return dfsHeight(root) != -1;
    }
};