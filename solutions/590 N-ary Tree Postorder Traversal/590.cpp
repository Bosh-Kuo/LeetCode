/*
time complexity: O(n)
tags: Stack, Tree, Depth-First Search
note: post-order traversal 為 DFS，在 recursion function 中先執行 children nodes，再執行本身
*/
class Solution
{
public:
    void postOrderTraversal(Node *root, vector<int> &answer)
    {
        if (root->children.size() != 0)
        {
            for (int i = 0; i < root->children.size(); i++)
            {
                postOrderTraversal(root->children[i], answer);
            }
        }
        answer.push_back(root->val);
    }
    vector<int> postorder(Node *root)
    {
        vector<int> answer;
        if (root != nullptr)
            postOrderTraversal(root, answer);
        return answer;
    }
};