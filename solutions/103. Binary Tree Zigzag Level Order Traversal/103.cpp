/*
time complexity O(n):
tags: Tree, Breath-First Search, Binary Tree
note: // 因為有時要從左至右，有時又從右至左，因此使用 deque 暫存準備要處理的 node，並用 leftToRight 決定該 level 的處理方向順序
將每個 level 的 nodes 獨立處理，
若該 level 的處理方向順序是左至右，則拿 dq 的最前面，並由左至右 dq.push_back
若該 level 的處理方向順序是右至左，則拿 dq 的最後面，並由右至左 dq.push_front
*/

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
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        vector<vector<int>> result;
        if (!root)
            return result;

        // 因為有時要從左至右，有時又從右至左，因此使用 deque 暫存準備要處理的 node
        // 用 leftToRight 決定該 level 的處理方向順序
        deque<TreeNode *> dq;
        dq.push_back(root);
        bool leftToRight = true;

        while (!dq.empty())
        {
            // 取得該 level 要處理的節點數量
            int size = dq.size();
            vector<int> level(size);

            for (int i = 0; i < size; i++)
            {
                // 若該 level 的處理方向順序是左至右，則拿 dq 的最前面，反則拿 dq 的最後面
                TreeNode *node = leftToRight ? dq.front() : dq.back();
                level[i] = node->val;

                if (leftToRight)
                {
                    if (node->left)
                        dq.push_back(node->left);
                    if (node->right)
                        dq.push_back(node->right);
                    dq.pop_front();
                }
                else
                {
                    if (node->right)
                        dq.push_front(node->right);
                    if (node->left)
                        dq.push_front(node->left);
                    dq.pop_back();
                }
            }

            leftToRight = !leftToRight;
            result.push_back(level);
        }

        return result;
    }
};