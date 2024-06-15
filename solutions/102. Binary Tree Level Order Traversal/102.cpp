/*
time complexity O(n):
tags: Tree, Breath-First Search, Binary Tree
note: 用 recursion 來做 pre-order traversal。 先處理自己在往左右走，雖然 recursion 為 DFS 的遍歷方式，但可以透過指定要加入的 level 用 DFS 解決 BFS 問題
*/

#include <iostream>
#include <vector>
using namespace std;


// Definition for a binary tree node.
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
    void recursion(int level, vector<vector<int>> &Ans, TreeNode* root)
    {
        if (!root)
            return;

        // 先處理自己
        // 若是該層第一個要加入 Ans 的 node 要先建立 vector
        if(Ans.size() == level)
        {
            vector<int> nodeInThisLevel = {root->val};
            Ans.push_back(nodeInThisLevel);
        }
        else
        {
            Ans[level].push_back(root->val);
        }

        // 先走 left node
        recursion(level + 1, Ans, root->left);

        //再走 right node
        recursion(level + 1, Ans, root->right);
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> Ans;
        recursion(0, Ans, root);
        return Ans;
    }
};
