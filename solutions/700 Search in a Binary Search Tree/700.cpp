/*
time complexity: O(log(n))
tags: Tree, Binary Search Tree, Binary Tree
note: 用 Recursion 來遍歷 BST，終止條件為找到指定 node 或是走到樹底為止
*/

#include <iostream>
using namespace std;

// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    TreeNode *searchBST(TreeNode *root, int val)
    {
        if (root == nullptr || root->val == val)
            return root;
        if (root->val > val)
            return searchBST(root->left, val);
        else
            return searchBST(root->right, val);
    }
};

int main()
{
    TreeNode node1 = TreeNode(1);
    TreeNode node3 = TreeNode(3);
    TreeNode node2 = TreeNode(2, &node1, &node3);
    TreeNode node7 = TreeNode(7);
    TreeNode node4 = TreeNode(4, &node2, &node7);
    Solution sol;
    TreeNode *ans = sol.searchBST(&node7, 2);
    if (ans == nullptr)
        cout << "NULL" << endl;
    else
        cout << ans->val << endl;
}