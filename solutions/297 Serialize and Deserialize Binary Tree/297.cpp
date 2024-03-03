/*
time complexity: O(n)
tags: String, Depth-First Search, Breadth-First Search, Design, Binary Tree
note: 以 pre-order traversal encode 與 decode，
encode: 若 node 本身為 nullptr 回傳 "#"，否則回傳 node->val + "#" -> 1#2###3#4###5###
decode: 用 getline 取 "#" 的數字作為 node->val，接著先處理 left node, 再處理 right node
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec
{
public:
    // Encodes a tree to a single string.
    // 用 preorder 順序 encode
    string serialize(TreeNode *root)
    {
        if (root == nullptr)
            return "#";
        else
            return to_string(root->val) + "#" + serialize(root->left) + serialize(root->right);
    }

    // Decodes your encoded data to tree.
    // 用 Preorder 順序 decode
    TreeNode *deserialize(string data)
    {
        stringstream ss(data);
        TreeNode *root = buildTree(ss);
        return root;
    }

    TreeNode *buildTree(stringstream &ss)
    {
        string token;
        getline(ss, token, '#');
        if (token == "")
            return nullptr;

        TreeNode *node = new TreeNode(stoi(token));
        node->left = buildTree(ss);
        node->right = buildTree(ss);
        return node;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
