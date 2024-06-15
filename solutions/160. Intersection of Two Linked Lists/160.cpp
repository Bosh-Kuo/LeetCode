/*
time complexity: O(m+n)
tags: Linked List, Hash Table, Two Pointers
note: 調整兩 list 出發點，使得兩 list 出發點到終點距離相同
*/

#include <iostream>
using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
    int getLengthOfList(ListNode *head)
    {
        int length = 0;
        while (head != NULL)
        {
            head = head->next;
            length++;
        }
        return length;
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        // 先找出 A 與 B 的長度
        int lengthA = getLengthOfList(headA);
        int lengthB = getLengthOfList(headB);

        // 使兩 List 長度一致 => 讓長度較長的 List 先走長度差個步數
        if (lengthA > lengthB)
        {
            int steps = lengthA - lengthB;
            while (steps > 0)
            {
                headA = headA->next;
                steps--;
            }
        }
        else if (lengthA < lengthB)
        {
            int steps = lengthB - lengthA;
            while (steps > 0)
            {
                headB = headB->next;
                steps--;
            }
        }

        // 兩 head 現在距離終點的距離達到一致，當在路上碰到實則回傳
        while (headA != NULL && headB != NULL)
        {
            if (headA == headB)
                return headA;
            headA = headA->next;
            headB = headB->next;
        }
        return NULL;
    }
};