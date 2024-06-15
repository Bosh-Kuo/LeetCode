/*
time complexity: O(n)
tags: Hash Table, Two Pointers, Tree, Depth-First Search, Breadth-First Search, Binary Search Tree, Binary Tree
note: 本題可以用 Hash Table 來存每個 node 的值，再找出 hash table 中可以組成 k 的兩個值，但如此就沒有運用到 BST。本題用 in order traversal，
將 BST 轉為一 sorted array，題目就變成 Two Sum 問題了
*/


#include <iostream>
#include <vector>
using namespace std;

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
    void inOrderTraversal(vector<int> &array, TreeNode* root)
    {
        if (root == nullptr)
            return;
        
        inOrderTraversal(array, root->left);
        array.push_back(root->val);
        inOrderTraversal(array, root->right);
    }
    bool findTarget(TreeNode *root, int k)
    {
        vector<int> array;
        inOrderTraversal(array, root);

        int i = 0, j = array.size() - 1;
        while(i < j)
        {
            if (array[i] + array[j] == k)
                return true;
            else if(array[i] + array[j] > k)
                j --;
            else
                i ++;
        }
        return false;
    }
};