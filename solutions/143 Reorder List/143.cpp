
/*
time complexity: O(n)
tags: Linked List, Two Pointers, Stack, Recursion
note: 用 Stack 把後段段的 Nodes 依序存入，在從第一個 Node 開始，將 Stack 中的 Nodes pop 出來，插入原 ＦList 的兩個 Node 之間
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    void reorderList(ListNode *head)
    {
        if (!head || !head->next || !head->next->next)
            return;

        ListNode *slow = head, *fast = head->next;
        stack<ListNode *> endStack;

        // 使用快慢指針找到中間節點
        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        // 從中間開始，將節點放入 stack
        while (slow->next)
        {
            slow = slow->next;
            endStack.push(slow);
        }

        ListNode *current = head;
        while (!endStack.empty())
        {
            ListNode *top = endStack.top();
            endStack.pop();

            ListNode *next = current->next;
            current->next = top;
            top->next = next;
            current = next;
        }

        // 確保新的尾節點指向 nullptr
        if (current)
        {
            current->next = nullptr;
        }
    }
};