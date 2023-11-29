/*
time complexity: O(n)
tags: Tree, Breadth-First Search
note: 用 queue 來 BFS。 讓 queue 中 node 的數量在 while loop 的開頭維持該 level 的 node 數，
並逐個加入 answer，並且將 node 的 children 加到 queue 中，直到 queue 被清空才跳出 while loop
*/

class Solution
{
public:
    vector<vector<int>> levelOrder(Node *root)
    {
        vector<vector<int>> answer;
        queue<Node *> nodes;
        if (root == nullptr)
            return answer;

        nodes.push(root);

        while (!nodes.empty())
        {
            vector<int> thisLevel;
            int numOfNodesInThisLevel = nodes.size();
            for (int i = 0; i < numOfNodesInThisLevel; i++)
            {
                // 取得 node
                Node *node = nodes.front();

                // 把該 node 的 children 加進 nodes
                if (node->children.size() > 0)
                    for (int j = 0; j < node->children.size(); j++)
                        nodes.push(node->children[j]);

                // 把 node->val 加進 thisLevel
                thisLevel.push_back(node->val);

                // 從 nodes 中移除 node
                nodes.pop();
            }
            answer.push_back(thisLevel);
        }
        return answer;
    }
};