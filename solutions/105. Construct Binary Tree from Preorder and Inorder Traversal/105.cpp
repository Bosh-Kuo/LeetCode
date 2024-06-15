/*
time complexity: O(n)
tags: Array, HashTable, Divide and Conquer, Tree, Binary Tree
note:
preorder array 的第一個 element 為 root node，但剩下的不知道哪些是左樹，哪些是右樹
inorder array 中，任意 node 的左子樹所有的 nodes 一定在其左半邊，右子樹所有的 node 一定在其右半邊
直觀推倒： 先從 preorder array 提出第一個 node 作為 root，然後找出該 root 在 inorder array 中的位置，左半邊就是其左樹的 nodes 右半邊就是其右樹的 nodes
從 inorder array 可以找到一個 node 的左樹 node 數量與右樹 node 數量， 可以用來區分在 preorder array 中，任意 node 後幾個 element 為屬於左樹，後幾個 element 為屬於右樹
若用 hash table 存下每個 node 在 inorder array 中的位置，可以快速找到左樹與右樹的 root 的位置
ref: https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/solutions/2279613/c-recursive-using-map-approaches/?orderBy=hot&languageTags=cpp
*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <utility>

using namespace std;

class Solution
{
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        unordered_map<int, int> inorderMap;
        for (int i = 0; i < inorder.size(); i++)
            inorderMap[inorder[i]] = i;

        pair<int, int> preorderRange(0, preorder.size() - 1);
        pair<int, int> inorderRange(0, inorder.size() - 1);
        TreeNode *root = construct(preorder, inorder, preorderRange, inorderRange, inorderMap);
        return root;
    }
    TreeNode *construct(vector<int> &preorder, vector<int> &inorder, pair<int, int> preorderRange, pair<int, int> inorderRange, unordered_map<int, int> &inorderMap)
    {

        int value = preorder[preorderRange.first];
        TreeNode *root = new TreeNode(value);

        int inorderIdx = inorderMap[value];
        pair<int, int> inorderLeftRange(inorderRange.first, inorderIdx - 1);
        pair<int, int> inorderRightRange(inorderIdx + 1, inorderRange.second);

        int numLeftNode = inorderLeftRange.second - inorderLeftRange.first + 1;
        int numRightNode = inorderRightRange.second - inorderRightRange.first + 1;

        if (numLeftNode > 0)
        {
            pair<int, int> preorderLeftRange(preorderRange.first + 1, preorderRange.first + numLeftNode);
            root->left = construct(preorder, inorder, preorderLeftRange, inorderLeftRange, inorderMap);
        }
        else
        {
            root->left = nullptr;
        }

        if (numRightNode > 0)
        {
            pair<int, int> preorderRightRange(preorderRange.second + 1 - numRightNode, preorderRange.second);
            root->right = construct(preorder, inorder, preorderRightRange, inorderRightRange, inorderMap);
        }
        else
        {
            root->right = nullptr;
        }
        return root;
    }
};