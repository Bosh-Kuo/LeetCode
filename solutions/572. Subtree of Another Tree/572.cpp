/*
time complexity: O(n)
tags: Tree, Depth-First Search, String Matching, Binary Tree, Hash Function
note: 若 current root 與 subRoot 相同，則開始比較兩棵樹是否完全相同，否則繼續往下 DFS
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
    bool compTwoTree(TreeNode *current, TreeNode *currentSub)
    {
        if (current == nullptr || currentSub == nullptr)
            return current == currentSub;
        if (current->val != currentSub->val)
            return false;
        return compTwoTree(current->left, currentSub->left) && compTwoTree(current->right, currentSub->right);
    }

    bool isSubtree(TreeNode *root, TreeNode *subRoot)
    {
        if (root == nullptr)
            return false;
        // 若 current root 與 subRoot 相同，則開始比較兩棵樹是否完全相同，否則繼續往下 DFS
        if (root->val == subRoot->val)
            if (compTwoTree(root, subRoot))
                return true;
            else
                return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
        else
            return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
};