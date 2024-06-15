/*
time complexity: O(n)
tags: Backtracking, Tree, Depth-First Search, Binary Tree
note: 用 DFS 遍歷每個節點，先將節點加入 path，再往左右節點走。在遍歷完左右結點後，從 path 移除當前的節點
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
    void dfs(vector<vector<int>> &ans, vector<int> &path, TreeNode *node, int target)
    {
        if (!node)
            return;

        path.push_back(node->val);

        // 若為 leaf 且 node->val 等於 target 時，將 path 加入 ans
        if (!node->left && !node->right && node->val == target)
            ans.push_back(path);

        dfs(ans, path, node->left, target - node->val);
        dfs(ans, path, node->right, target - node->val);
        path.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode *root, int targetSum)
    {
        vector<vector<int>> ans;
        vector<int> path;
        dfs(ans, path, root, targetSum);
        return ans;
    }
};