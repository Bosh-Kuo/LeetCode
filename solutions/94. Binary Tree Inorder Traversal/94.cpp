/*
time complexity O(n):
tags: Stack, Tree, Depth-First Search, Binary Tree
note: 用 recursion 來做 in-order traversal。先往 left node 走，left tree 都走過後接著處理當前的 root node，再往 right node 走
*/

#include <iostream>
#include <vector>
using namespace std;


// Definition for a binary tree node
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    void recursion(TreeNode *root, vector<int> &Ans)
    {
        if (!root)
            return;

        // 先往 left node 走
        recursion(root->left, Ans);

        // left tree 都走過後把自己加入 Ans
        Ans.push_back(root->val);

        // 再往 right node 走
        recursion(root->right, Ans);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> Ans;
        recursion(root, Ans);
        return Ans;
    }
};


int main()
{
    TreeNode node3 = TreeNode(3);
    TreeNode node2 = TreeNode(2, &node3, nullptr);
    TreeNode node1 = TreeNode(1, nullptr, &node2);
    Solution sol;
    vector<int> Ans = sol.inorderTraversal(&node1);
    for (int nodeValue: Ans)
        cout << nodeValue << " ";
    
     
}