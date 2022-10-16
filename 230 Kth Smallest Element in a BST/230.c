/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

void inOrder(struct TreeNode* root, int* countPtr, int k, int* ans)
{
        
    // 該 node 為 left    
    if (root->left == NULL && root->right == NULL && *countPtr < k)
    {
        *countPtr += 1;
        if(*countPtr == k)
            *ans = root->val;
    }
    else
    {
        // left
        if (root->left != NULL)
            inOrder(root->left, countPtr, k, ans);
        
        // root
        *countPtr += 1;
        if(*countPtr == k)
            *ans = root->val;
        
        // right
        if (root->right != NULL)
            inOrder(root->right, countPtr, k, ans);
    }
    
}

int kthSmallest(struct TreeNode* root, int k){
    int count = 0;
    int ans = 0;
    inOrder(root, &count, k, &ans);
    return ans;
}