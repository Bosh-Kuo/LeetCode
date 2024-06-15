/*
time complexity: O(n)
tags: Array, Divide and Conquer, Tree, Binary Search Tree, Binary Tree
note: 將 nums 分割成左半->left child、右半->right child、中間->current
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
    TreeNode *insertToBST(vector<int> &nums, int l, int r)
    {
        // 終止條件
        if (l > r)
            return nullptr;

        // 令中間值為 root
        int mid = (l + r) / 2;
        TreeNode *root = new TreeNode(nums[mid]);
        root->right = insertToBST(nums, mid + 1, r);
        root->left = insertToBST(nums, l, mid - 1);
        return root;
    }
    TreeNode *sortedArrayToBST(vector<int> &nums)
    {
        TreeNode *root = insertToBST(nums, 0, nums.size() - 1);
        return root;
    }
};