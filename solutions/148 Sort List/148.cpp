/**
time complexity: O(n*log(n))
tags: Linked List, Two Pointers, Divide and Conquer, Sorting, Merge Sort
note: 用 Divide and Conquer 令 left 為 sort 好的左半， right 為 sort 好的右半，再回傳 merge(left, right)

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
    ListNode *sortList(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr)
            return head;

        // divide: 將 list 分成兩半
        ListNode *fast = head->next->next, *slow = head;
        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *rightHead = slow->next;
        slow->next = nullptr;
        ListNode *left = sortList(head);
        ListNode *right = sortList(rightHead);

        // conquer: 回傳 merge 後的 list
        return merge(left, right);
    }

    ListNode *merge(ListNode *left, ListNode *right)
    {
        ListNode *dummy = new ListNode();
        ListNode *current = dummy;
        while (left && right)
        {
            if (left->val < right->val)
            {
                current->next = left;
                left = left->next;
            }
            else
            {
                current->next = right;
                right = right->next;
            }
            current = current->next;
        }
        if (left)
            current->next = left;
        else
            current->next = right;

        return dummy->next;
    }
};