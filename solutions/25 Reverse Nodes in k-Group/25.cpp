/*
time complexity : O(n)
tags: Linked List, Recursion
note:
1. 先取得 list 的長度
2. dummyHead 連向 head
3. 從 dummy head 開始，令 reverseList 回傳 reversed k nodes 的 head，將 current->next 改指向 reversed k nodes 的 head
再令 current 為原本的 current->next，也就是 reversed k nodes 的最後一個 node
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
    int getLength(ListNode *head)
    {
        int length = 0;
        while (head != nullptr)
        {
            head = head->next;
            length++;
        }
        return length;
    }
    ListNode *reverseList(ListNode *head, int k)
    {
        int count = 0;
        ListNode *current = head;
        ListNode *last = nullptr;
        while (count < k)
        {
            ListNode *next = current->next; // 保留原本的 next
            current->next = last;           // 將 next 指向原本的 last
            last = current;                 // head 將成為下一輪的 last
            current = next;                 // 走向原本的 next
            count++;
        }
        head->next = current; // 此時的 current 是原本 k's node 的 next
        return last;
    }
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        // 1. 先取得 list 的長度
        int length = getLength(head);

        // 2. dummyhead 連向 head
        ListNode *dummyHead = new ListNode();
        dummyHead->next = head;
        ListNode *current = dummyHead;
        int currentIdx = 0;

        while (length - currentIdx >= k)
        {
            ListNode *next = current->next;                // 保留原本的 current->next， reverse 後會變成 reversed k nodes 的最後一個
            current->next = reverseList(current->next, k); // current->next 接上 reverse k nodes 的 head
            current = next;                                // 走到原本的 current->next，也就是 reversed k nodes 的最後一個
            currentIdx += k;
        }
        return dummyHead->next;
    }
};