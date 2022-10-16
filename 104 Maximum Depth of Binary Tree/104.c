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


void findDepth(struct TreeNode* root, int count, int* depth)
{
    if(root == NULL)
    {
        if(count > *depth)
        {
            *depth = count;
        }
        return;
    }
    findDepth(root->left, count+1, depth);
    findDepth(root->right, count+1, depth);
}

int maxDepth(struct TreeNode* root){
    int depth = 0;
    findDepth(root, 0, &depth);
    return depth;
}