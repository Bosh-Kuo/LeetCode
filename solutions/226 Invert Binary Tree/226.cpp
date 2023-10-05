/*
time complexity : O(n)
tags: Tree, Depth-First Search, Breadth-First Search, Binary Tree
note: 用 pre-order traversal DFS 交換 left, right nodes
 */

#include <iostream>

class Solution
{
public:
    void preOrder(TreeNode *root)
    {
        if (root == NULL)
            return;
        TreeNode *temp = root->left;
        root->left = root->right;
        root->right = temp;

        preOrder(root->left);
        preOrder(root->right);
    }
    TreeNode *invertTree(TreeNode *root)
    {
        preOrder(root);
        return root;
    }
};