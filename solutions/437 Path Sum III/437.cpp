/*
time complexity: O(n^2)
tags: Tree, Depth-First Search, Binary Tree
note: 用 DFS 搜尋包含 root 節點的所有路徑，接著分別以 left, right 作為 root 再搜一次，直到所有節點都當過一次 root 為止
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
    int pathSum(TreeNode *root, int targetSum)
    {
        if (root)
        {
            dfs(root, targetSum);
            pathSum(root->left, targetSum);
            pathSum(root->right, targetSum);
        }
        return ans;
    }

    void dfs(TreeNode *root, long long sum)
    {
        if (!root)
            return;
        if (root->val == sum)
            ans++;
        dfs(root->left, sum - root->val);
        dfs(root->right, sum - root->val);
    }
};