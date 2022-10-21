/*
time complexity: O(n)
tags: Tree, Depth-First Search, Breadth-First Search, Binary Tree
note: 對每個 node 來說，max Depth 為 left node 與 right node 的 max Depth 較大者加 1 (自己)，原問題被轉換成算 left node's max Depth 與 right node's max Depth 的子問題，
適合用 recursion 解
*/

#include <iostream>
#include <algorithm>
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
    int maxDepth(TreeNode *root)
    {
        if (root == nullptr)
            return 0;
        else
            return max(1 + maxDepth(root->left), 1 + maxDepth(root->right));
    }
};

int main()
{
    TreeNode node_15 = TreeNode(15);
    TreeNode node_7 = TreeNode(7);
    TreeNode node_20 = TreeNode(20, &node_15, &node_7);
    TreeNode node_9 = TreeNode(9);
    TreeNode node_3 = TreeNode(3, &node_9, &node_20);
    Solution sol;
    cout << sol.maxDepth(&node_3) << endl;
}