/*
time complexity: O(n)
tags: Tree, Depth-First Search, Binary Tree
note: 對於每個 node 來說，以該 node 為 root 可以得到的 diameter = maxLeftLength + maxRightLength
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
    int ans = 0;
    int maxLength(TreeNode *root)
    {
        if (root == nullptr)
            return 0;
        int maxLeftLength = maxLength(root->left);
        int maxRightLength = maxLength(root->right);
        ans = max(ans, maxLeftLength + maxRightLength);
        return 1 + max(maxLeftLength, maxRightLength);
    }

    int diameterOfBinaryTree(TreeNode *root)
    {
        // 對於每個 node 來說，以該 node 為 root 可以得到的 diameter = maxLeftLength + maxRightLength
        int maxRootLength = maxLength(root);
        return ans;
    }
};