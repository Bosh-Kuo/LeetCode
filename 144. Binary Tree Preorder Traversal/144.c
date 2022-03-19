#include <stdio.h>
#include <stdlib.h>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

void preorder(struct TreeNode *root, int *result, int * size)
{
    if(root == NULL) 
        return;
    
    result[(*size)] = root->val;
    (*size) = (*size) += 1;
    preorder(root->left, result, size);
    preorder(root->right, result, size);
}

int* preorderTraversal(struct TreeNode* root, int* returnSize){
    int * result = (int *)malloc(100*sizeof(int));
    *returnSize = 0;
    preorder(root, result, returnSize);
    return result;
}

