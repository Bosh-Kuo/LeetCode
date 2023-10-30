/*
time complexity : O(n)
tags: Linked List
note: 先將第一個基數 node 與 偶數 node 找出來，交替著讓基數 node 與偶數 node 指向 ->next->next，再將最後一個基數 node 的 next 指向偶數 list 的第一個 node
*/

class Solution
{
public:
    ListNode *oddEvenList(ListNode *head)
    {
        ListNode *oddIndicesNode = head;
        ListNode *evenIndicesNode = head != nullptr ? head->next : nullptr;
        ListNode *oddHead = oddIndicesNode;
        ListNode *evenHead = evenIndicesNode;

        // 當總 nodes 數為偶數時，evenHead->next 為 nullptr，
        // 當總 nodes 數為 0 or 1 時， evenHead 為 ptr，這兩種情況皆可以直接連接奇數與偶數 list
        while ((evenHead != nullptr && evenHead->next != nullptr))
        {
            // 處理奇數 node
            oddHead->next = evenHead->next;
            oddHead = evenHead->next;

            // 處理偶數 node
            // 當為最後一個 even node 時
            if (!evenHead->next->next)
                evenHead->next = nullptr;
            else
                evenHead->next = evenHead->next->next;
            evenHead = evenHead->next;
        }
        if (!oddIndicesNode && !evenIndicesNode)
            return nullptr;
        else
            oddHead->next = evenIndicesNode;
        return oddIndicesNode;
    }
};