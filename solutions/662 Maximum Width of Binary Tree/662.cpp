/*
time complexity: O(n)
tags: Tree, Depth-First Search, Breadth-First Search, Binary Search
note: 使用 queue 來暫存每層 layer 要遍歷的 node，並用 pair<TreeNode*, long long> 儲存該 node 在帕斯卡三角形中對應的數值
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution
{
public:
    long long ans = 1;
    void bfs(queue<pair<TreeNode *, long long>> &layerNodes)
    {
        queue<pair<TreeNode *, long long>> nextLayerNodes;
        pair<TreeNode *, long long> left = layerNodes.front();
        pair<TreeNode *, long long> right = layerNodes.back();
        ans = max(ans, (right.second - left.second + 1));

        long long layerMin = left.second;
        while (!layerNodes.empty())
        {
            TreeNode *node = layerNodes.front().first;
            long long value = layerNodes.front().second - layerMin + 1; // 平移，避免超過 long long 範圍
            layerNodes.pop();
            if (node->left != nullptr)
                nextLayerNodes.push({node->left, value * 2 - 1});
            if (node->right != nullptr)
                nextLayerNodes.push({node->right, value * 2});
        }
        if (!nextLayerNodes.empty())
            bfs(nextLayerNodes);
    }

    int widthOfBinaryTree(TreeNode *root)
    {
        // 用 bfs 比較同一層的最大最小值
        queue<pair<TreeNode *, long long>> layerNodes;
        layerNodes.push({root, 1});
        bfs(layerNodes);
        return ans;
    }
};
