/*
time complexity : O(n)
tags: Linked List, Math, Recursion
note: 從最小位數，也就是最前面的 head 開始算該位數的值，並且考慮進位
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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *dummyHead = new ListNode();
        ListNode *head = dummyHead;

        int sum = 0, carry = 0;
        while (l1 != nullptr || l2 != nullptr)
        {
            int first = l1 != nullptr ? l1->val : 0;
            int second = l2 != nullptr ? l2->val : 0;
            int digit;
            if (first + second + carry >= 10)
            {
                digit = first + second + carry - 10;
                carry = 1;
            }
            else
            {
                digit = first + second + carry;
                carry = 0;
            }
            // 新增一個 Node， value 為 degit
            ListNode *newHead = new ListNode(digit);
            head->next = newHead;
            head = head->next;

            // l1, l2 move on
            l1 = l1 == nullptr ? l1 : l1->next;
            l2 = l2 == nullptr ? l2 : l2->next;
        }
        if (carry > 0)
        {
            ListNode *newHead = new ListNode(carry);
            head->next = newHead;
        }
        return dummyHead->next;
    }
};