/*
time complexity: O(n)
tags: Tree, Depth-First Search, Binary Search Tree, Binary Tree
note: 當前的節點對左子樹來說必是最大值，當前的節點對右子樹來說必是最小值。用 DFS 從 left node 開始檢查。
node 的 left child 必須小於該 node，node 的 right child 必須大於該 node，
若 node 的任一子樹回傳為 False ，便向 parent node 回傳 False
*/

#include <iostream>
#include <limits>
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
    bool recursion(TreeNode *root, long small, long big)
    {
        // base case
        if (root == nullptr)
            return true;
        // divide
        // 當前的節點對左子樹來說必是最大值
        // 當前的節點對右子樹來說必是最小值
        if (recursion(root->left, small, root->val) && recursion(root->right, root->val, big))
        {
            return (root->val < big) && (root->val > small);
        }
        else
            return false;
    }

    bool isValidBST(TreeNode *root)
    {
        return recursion(root, LONG_MIN, LONG_MAX);
    }
};

int main()
{
    Solution sol;
    TreeNode node1 = TreeNode(1);
    TreeNode node3 = TreeNode(3);
    TreeNode node6 = TreeNode(6);
    TreeNode node4 = TreeNode(4, &node3, &node6);
    TreeNode node5 = TreeNode(5, &node1, &node4);
    cout << sol.isValidBST(&node4);
}