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

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
void checkView(struct TreeNode * root, int * result, bool * view, int * idx, int height)
{
    if(root == NULL) return;
    if(view[height] == false)
    {
        result[(*idx)] = root->val;  // 第一個 right tree 
        (*idx)++;
    }
    view[height] = true;  // 代表在這個高度已經看過最右邊的樹了
    checkView(root->right, result, view, idx, height + 1);  // 先走右邊
    checkView(root->left, result, view, idx, height + 1);
}
int* rightSideView(struct TreeNode* root, int* returnSize){
    bool * view = (bool *)calloc(100, sizeof(bool));
    int * result = (int *)malloc(100*sizeof(int));
    int idx = 0;
    checkView(root, result, view, &idx, 0);
    *returnSize = idx;
    return result;   
}