#include <stdio.h>
#include <stdlib.h>

// Definition for a binary tree node.
struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

void traversal(struct TreeNode *root, int *result, int *size)
{
    if (root == NULL)
        return;

    traversal(root->left, result, size);
    traversal(root->right, result, size);
    result[(*size)] = root->val;
    (*size) = (*size) += 1;
}

int *postorderTraversal(struct TreeNode *root, int *returnSize)
{
    int *result = (int *)malloc(100 * sizeof(int));
    *returnSize = 0;
    traversal(root, result, returnSize);
    return result;
}