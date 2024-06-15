/*
time complexity: O(n)
tags: String, Tree, Depth-First Search, Breadth-First Search, Design, Binary Search Tree, Binary Tree
note:
serialize: 將 BST 以 pre-order traversal 表示，以 ',' 分隔節點，'-1' 表示空節點。
deserialize: 由於輸入的 string 為 pre-order 的順序，因此重建 BST 時同樣以先建左子樹在建右子樹的順序建立
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
    string serialize(TreeNode *root)
    {
        if (!root)
            return "-1,"; // 用-1表示空節點

        // 使用stringstream來建構字串，因為它比直接使用string拼接效率更高
        stringstream ss;
        serializeHelper(root, ss);
        return ss.str();
    }

    // 輔助函數，用於遞迴地序列化樹
    void serializeHelper(TreeNode *node, stringstream &ss)
    {
        if (!node)
        {
            ss << "-1,"; // 空節點用-1表示
            return;
        }

        // 前序遍歷：根節點 -> 左子樹 -> 右子樹
        ss << node->val << ",";
        serializeHelper(node->left, ss);
        serializeHelper(node->right, ss);
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data)
    {
        stringstream ss(data); // 使用stringstream方便地讀取字串中的整數
        return deserializeHelper(ss);
    }

    // 輔助函數，用於遞迴地反序列化字串為樹
    TreeNode *deserializeHelper(stringstream &ss)
    {
        string val;
        getline(ss, val, ','); // 讀取到逗號為止的字串
        if (val == "-1")
            return nullptr; // 遇到-1表示空節點

        TreeNode *node = new TreeNode(stoi(val));
        node->left = deserializeHelper(ss);  // 遞迴建構左子樹
        node->right = deserializeHelper(ss); // 遞迴建構右子樹
        return node;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;