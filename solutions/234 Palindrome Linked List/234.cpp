/*
time complexity: O(n)
tags: Linked List, Two Pointers, Stack, Recursion
note: 先用 two pointes 找到 linked list 中間點將 linked list 分兩半，接著將後半反轉，最後比較前半與反轉後的後半，
*/

#include <iostream>
using namespace std;

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
    ListNode *findFirstHalfEnd(ListNode *head)
    {
        ListNode *fast = head;
        ListNode *slow = head;
        while (fast->next != nullptr && fast->next->next != nullptr)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }
    ListNode *reverse(ListNode *head)
    {
        ListNode *current = head;
        ListNode *previous = nullptr;
        while (current != nullptr)
        {
            ListNode *nextNode = current->next;
            current->next = previous;
            previous = current;
            current = nextNode;
        }
        return previous;
    }
    bool isPalindrome(ListNode *head)
    {
        ListNode *firstHalfEnd = findFirstHalfEnd(head);
        ListNode *secondHalfEnd = firstHalfEnd->next;
        ListNode *secondHalfStart = reverse(secondHalfEnd);
        while(secondHalfStart != nullptr)
        {
            if(secondHalfStart->val != head->val)
                return false;
            secondHalfStart = secondHalfStart->next;
            head = head->next;
        }
        return true;
    }
};
