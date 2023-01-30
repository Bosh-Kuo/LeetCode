/*
time complexity: O(n)
tags: Dynamic Programming, Tree, Depth-First Search, Binary Search
note: max sum path 的組成可能有 4 種可能：
1. 某單一 node 本身
2. 某 node + 左樹最大路徑
3. 某 node + 右樹最大路徑
4. 某 node + 左樹最大路徑 + 右樹最大路徑
2, 3, 4 其實概念類似，只要令左or右樹最大路徑於 0 時回傳 0，就可以一律用 4 來表達
ref:
https://leetcode.com/problems/binary-tree-maximum-path-sum/solutions/3093544/java-c-100-solution-using-depth-first-search-binary-tree-maximum-path-sum/?orderBy=hot&languageTags=cpp
https://leetcode.com/problems/binary-tree-maximum-path-sum/solutions/2827786/binary-tree-maximum-path-sum/?orderBy=hot
*/

#include <iostream>
#include <algorithm>

using namespace std;

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
    int maximum = INT_MIN;
    int dfs(TreeNode *root)
    {
        if (!root)
            return 0;
        int maxLeft = dfs(root->left);
        int maxRight = dfs(root->right);
        maximum = max(maximum, root->val + maxLeft + maxRight);

        // 以該 node 作為 root 的最大單一路徑 (朝左 dfs or 朝右 dfs)
        // 這條路徑將會是該 node 的 parent node 的 maxLeft or maxRight
        int maxSinglePath = root->val + max(maxLeft, maxRight);
        if (maxSinglePath < 0)
            maxSinglePath = 0;

        return maxSinglePath;
    }
    int maxPathSum(TreeNode *root)
    {
        dfs(root);
        return maximum;
    }
};