/*
time complexity: O(n)
tags: Recursion, Linked List
note: 如果目前的 head 不須移除，則在 head->next 接上一個已經移除好的 linked list；如果目前的 head 需要移除，則直接把問題丟給下個 Node。如果此 list 為 nullptr 則直接回傳 nullptr
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
    ListNode *removeElements(ListNode *head, int val)
    {
        if (head == nullptr)
            return head;
        if (head->val == val)
            return removeElements(head->next, val);
        else
            head->next = removeElements(head->next, val);

        return head;
    }
};