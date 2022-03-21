#include <stdio.h>
#include <stdlib.h>

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

void findDepth(struct TreeNode *root, int counter, int *depth)
{
    if (root == NULL)
    {
        if (counter > *depth)
            *depth = counter;
        return;
    }
    findDepth(root->left, counter + 1, depth);
    findDepth(root->right, counter + 1, depth);
}

void travel(struct TreeNode *root, int **returnColumnSizes, int level, int **result)
{
    if (root == NULL)
        return;
    result[level][(*returnColumnSizes)[level]] = root->val;
    (*returnColumnSizes)[level] += 1;
    travel(root->left, returnColumnSizes, level + 1, result);
    travel(root->right, returnColumnSizes, level + 1, result);
}

int **levelOrder(struct TreeNode *root, int *returnSize, int **returnColumnSizes)
{
    int depth = 0;
    findDepth(root, 0, &depth);
    int **result = (int **)malloc(sizeof(int *) * depth);
    for (int i = 0; i < depth; i++)
    {
        result[i] = (int *)malloc(sizeof(int) * 1000);
    }
    *returnColumnSizes = (int *)calloc(depth, sizeof(int));
    travel(root, returnColumnSizes, 0, result);
    *returnSize = depth;
    return result;
}