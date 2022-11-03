/*
time complexity:
tags: Dynamic Programming, Backtracking, Tree, Binary Search Tree, Binary Tree
note: 首先，從 1 ~ n 每個數字都會輪流當 BST 的 root，當輪到 k 當 root 時，1 ~ k-1 會在 k 的左半邊組成多種 BST，
同理 k+1 ~ n 則會在 k 右邊組成多種 BST，可以發現左右半邊的任務同樣是『組成多種 BST』這件事，只是範圍縮小了，
因此可以用 recursive (divide and conquer) 的概念來處理
*/

#include <iostream>
#include <vector>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    vector<TreeNode *> buildTree(int start, int end)
    {
        vector<TreeNode *> ans;

        if (start == end)
        {
            ans.push_back(new TreeNode(start));
            return ans;
        }
        if (start > end)
        {
            ans.push_back(nullptr);
            return ans;
        }

        // 從 start 到 end 輪流當 root
        for (int i = start; i <= end; i++)
        {
            vector<TreeNode *> leftTrees = buildTree(start, i - 1); // 輪到 i 當 root 時，start ~ i-1 在左半邊組合成所有可能的 leftTrees
            vector<TreeNode *> rightTrees = buildTree(i + 1, end);  // 輪到 i 當 root 時，i+1 ~ end 在右半邊組合成所有可能的 rightTrees
            for (auto leftTreeRoot : leftTrees)
                for (auto rightTreeRoot : rightTrees)
                {
                    TreeNode *root = new TreeNode(i, leftTreeRoot, rightTreeRoot);
                    ans.push_back(root); // 輪到 i 當 root 時，以 i 為 root，範圍從 start ~ end 所有可能的 trees
                }
        }

        return ans;
    }
    vector<TreeNode *> generateTrees(int n)
    {
        return buildTree(1, n);
    }
};

void inOrder(TreeNode *root)
{
    if (root == nullptr)
        cout << "null ";
    else
    {
        cout << root->val << " ";
        inOrder(root->left);
        inOrder(root->right);
    }
}

int main()
{
    Solution sol;
    vector<TreeNode *> ans = sol.generateTrees(3);
    for (auto root : ans)
    {
        inOrder(root);
        cout << endl;
    }
}