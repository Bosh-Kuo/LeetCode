/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

bool traverse(struct TreeNode* node, int targetSum)
{
    // 扣除當前 node value 後為新的 targetSum，若到達 leaf 時剛好為 0 即為 true
    targetSum -= node->val;

    // 到達 leaf 後開始檢查
    if(!node->left && !node->right && targetSum == 0)  
        return true;
    else if (!node->left && !node->right && targetSum != 0)
        return false;
    
    
    if (node->left)  // 左子樹存在才走
    {
        if(traverse(node->left, targetSum))
            return true;
    }
    if (node->right)  // 右子樹存在才走
    {
        if(traverse(node->right, targetSum))
            return true;
    }
    return false;

}


bool hasPathSum(struct TreeNode* root, int targetSum){
    if (root == NULL)
        return false;
    return traverse(root, targetSum);
}