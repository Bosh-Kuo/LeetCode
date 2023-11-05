/*
time complexity: O(n)
tags:  Hash Table, Linked
note: 用 Hash Table 紀錄原 linked list 的 nodes 與 copy linked list 的 nodes 的對應關係，
如果 copy linked list 的 node->next or node->random 已經被創建過了，會被存在 Hash Table 中，可以直接拿來使用
若尚未被創建過，則創建後再加入 Hash Table

/*
Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution
{
public:
    Node *copyRandomList(Node *head)
    {
        if (head == nullptr)
            return head;

        // 建立一個原 node 與 copy node 的對照 hashTable
        unordered_map<Node *, Node *> hashTable;

        // 建立新的 head Node
        Node *newHead = new Node(head->val);
        Node *current = newHead;
        // 將 head 與 newHead 對照關係加入 hashTable
        hashTable[head] = newHead;

        while (current != nullptr)
        {
            // 找出 next，如果 next 不為 null，則建立一個 copy，並且指過去
            Node *next = head->next;
            if (next != nullptr)
            {
                // 如果 newNext 已經在之前被創建過，則直接指向該 nexNext
                if (hashTable.count(next))
                    current->next = hashTable[next];
                // 否則建立一個新的 nexNext，並且指過去以及加入 hashTable
                else
                {
                    Node *newNext = new Node(next->val);
                    current->next = newNext;
                    hashTable[next] = newNext;
                }
            }

            // 確認 random 指的 Node 是否已存在，若存在則直接指過去
            if (hashTable.count(head->random))
                current->random = hashTable[head->random];
            // 若不存在，就建立出一個 copy，並且指過去以及加入 hashTable
            else
            {
                if (head->random == nullptr)
                    hashTable[head->random] = nullptr;
                else
                {
                    Node *newRandom = new Node(head->random->val);
                    current->random = newRandom;
                    hashTable[head->random] = newRandom;
                }
            }
            current = current->next;
            head = head->next;
        }
        return newHead;
    }
};