#include <stdio.h>
#include <stdlib.h>

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

bool compare(struct TreeNode *leftTree, struct TreeNode *rightTree)
{
    // 空節點
    if (leftTree == NULL && rightTree == NULL)
        return true;
    else if ((leftTree == NULL && rightTree != NULL) || (rightTree == NULL && leftTree != NULL))
        return false;
    // 非空節點
    else if (leftTree->val != rightTree->val)
        return false;
    bool outside = compare(leftTree->left, rightTree->right);  // 左樹：左, 右樹：右
    bool inside = compare(leftTree->right, rightTree->left);   // 左樹：右, 右樹：左
    return (outside && inside);
}

bool isSymmetric(struct TreeNode *root)
{
    if (root == NULL)
        return false;
    return compare(root->left, root->right);
}