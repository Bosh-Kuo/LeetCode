/*
time complexity: O(n)
tags: Stack, Tree, Depth-First Search
note: pre-order traversal 為 DFS，在 recursion function 中先執行本身，再逐個執行 children nodes
*/
class Solution
{
public:
    void preOrderTraversal(Node *root, vector<int> &answer)
    {
        if (root == nullptr)
            return;
        answer.push_back(root->val);
        int numOfChildren = root->children.size();
        for (int i = 0; i < numOfChildren; i++)
        {
            preOrderTraversal(root->children[i], answer);
        }
    }
    vector<int> preorder(Node *root)
    {
        vector<int> answer;
        preOrderTraversal(root, answer);
        return answer;
    }
};