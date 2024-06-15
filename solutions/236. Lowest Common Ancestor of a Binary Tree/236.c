/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
    if (root == p || root == q || root == NULL)
        return root;
    struct TreeNode* left = lowestCommonAncestor(root->left, p, q);
    struct TreeNode* right = lowestCommonAncestor(root->right, p, q);
    
    if(left != NULL && right != NULL)
        return root;
    if(left != NULL && right == NULL)
        return left;
    else if(left == NULL && right != NULL)
        return right;
    else
        return left;
}