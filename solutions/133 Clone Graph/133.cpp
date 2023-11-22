/*
time complexity:
tags: Hash Table, Depth-First Search, Breadth-First Search, Graph
note: 本題用 BFS，逐個遍歷所有 node。並且用 hashTable 紀錄以建立的 node。
若 neighbor 已建立，直接使用而不用新建。BFS 時，若 neighbor 的 neighbors 若為不為空，代表已被走訪過，就不用網該 neighbor BFS
*/

class Solution
{
public:
    void BFS(Node *originalNode, Node *newNode, unordered_map<int, Node *> &hashTable)
    {
        // 先將原 node 的 neighbors 加入 newNode 的 neighbors
        for (int i = 0; i < originalNode->neighbors.size(); i++)
        {
            Node *originalNeighbor = originalNode->neighbors[i];
            Node *newNeighbor;

            // 如果該 node 還沒被建立過，則建立，並且加入 hash table
            if (!hashTable.count(originalNeighbor->val))
            {
                newNeighbor = new Node(originalNeighbor->val);
                hashTable[newNeighbor->val] = newNeighbor;
            }
            else
            {
                newNeighbor = hashTable[originalNeighbor->val];
            }
            // 加入 newNode 的 neighbors 裡
            newNode->neighbors.push_back(newNeighbor);
        }

        // BFS
        for (int i = 0; i < newNode->neighbors.size(); i++)
        {
            Node *originalNeighbor = originalNode->neighbors[i];
            Node *newNeighbor = newNode->neighbors[i];

            if (newNeighbor->neighbors.size() == 0)
                BFS(originalNeighbor, newNeighbor, hashTable);
        }
    }

    Node *cloneGraph(Node *node)
    {
        // 極端情況
        if (node == nullptr)
            return nullptr;

        // 建立一個 hash table 紀錄哪些 node 已經被創建過了
        unordered_map<int, Node *> hashTable;

        // 建立第一個 node 並且加入 hash table
        Node *newNode = new Node(node->val);
        hashTable[node->val] = newNode;

        // 執行 BFS
        BFS(node, newNode, hashTable);

        return newNode;
    }
};
