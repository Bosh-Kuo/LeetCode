/*
time complexity: O(n)
tags: Linked List, Depth-First Search, Doubly-Linked List
note: 由於做先遇到的岔路要最後處理，因此用 stack 來做 DFS。
*/

/*
Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution
{
public:
    Node *flatten(Node *head)
    {
        stack<Node *> nodeStack;
        Node *current = head;
        while (current != nullptr)
        {
            // 如果 current 已經是該 path 的最後一個 node: 將 nodeStack 的 Node 接上
            if (current->next == nullptr)
            {
                // 如果 nodeStack 已經清空則不做動作
                if (!nodeStack.empty())
                {
                    Node *nextNode = nodeStack.top();
                    nodeStack.pop();
                    current->next = nextNode;
                    nextNode->prev = current;
                }
            }

            // 如果 current->child 沒接 Node 則直接往下走
            if (current->child == nullptr)
                current = current->next;
            else
            {
                // 現將本來的 next 用 stack 暫存起來
                if (current->next != nullptr)
                    nodeStack.push(current->next);
                // 將 current->child 轉為 current->next
                current->next = current->child;
                current->child->prev = current;
                current->child = nullptr;
                // current 往原本的 child 方向走
                current = current->next;
            }
        }
        return head;
    }
};