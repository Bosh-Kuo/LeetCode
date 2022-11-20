/*
time complexity: O(n)
tags: Tree, Depth-First Search, Breadth-First Search, Binary Tree
note: 這題用 stack iteration 代替迭代的方法來做，將同位置的 node pair 加入 stack 裡面一個個檢查(DFS)
*/

#include <iostream>
#include <stack>
#include <utility>
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
    bool check(TreeNode *p, TreeNode *q)
    {
        // both nullptr
        if (!p && !q)
            return true;
        // one is nullptr
        if (!p || !q)
            return false;
        // both has different value
        if (p->val != q->val)
            return false;
        return true;
    }
    bool isSameTree(TreeNode *p, TreeNode *q)
    {
        // use stack to replace recursive call
        stack<pair<TreeNode *, TreeNode *>> nodePairs;

        // root pair
        pair<TreeNode *, TreeNode *> rootPair(p, q);

        // 加入 stack
        nodePairs.push(rootPair);

        // 用 stack 取代 recursion，一組一組檢查
        while (!nodePairs.empty())
        {
            pair<TreeNode *, TreeNode *> nodePair = nodePairs.top();
            // pop 掉確認過的 pair
            nodePairs.pop();
            // cout << nodePair.first->val << " " << nodePair.second->val << endl;

            if (!check(nodePair.first, nodePair.second))
                return false;
            else
            {
                // pair 都不為 null 就繼續檢查
                if (nodePair.first && nodePair.second)
                {
                    pair<TreeNode *, TreeNode *> leftPair(nodePair.first->left, nodePair.second->left);
                    pair<TreeNode *, TreeNode *> rightPair(nodePair.first->right, nodePair.second->right);
                    nodePairs.push(leftPair);
                    nodePairs.push(rightPair);
                }
            }
        }
        return true;
    }
};

int main()
{
    TreeNode node1_2 = TreeNode(2);
    TreeNode node2_2 = TreeNode(2);
    TreeNode node1_3 = TreeNode(3);
    TreeNode node2_3 = TreeNode(3);
    TreeNode root1 = TreeNode(1, &node1_2, &node1_3);
    TreeNode root2 = TreeNode(1, &node2_2, &node2_3);

    Solution sol;
    cout << sol.isSameTree(&root1, &root2);
}