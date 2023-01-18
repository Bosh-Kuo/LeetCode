/*
time complexity: O(n)
tags: Linked List, Two Pointers
note: 若 k >= n ，實際上只要 rotate k % n 次而已。以 0 為 index base， (n-k)-th node 為 new head node， (n-k-1)-th node 為 new end node，
原本的 end node 要指向原本的 head node。
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
class Solution {
public:
    int linkLength(ListNode* head)
    {
        int length = 0;
        while(head!=nullptr)
        {
            head = head->next;
            length += 1;
        }
        return length;
    }
    ListNode* rotateRight(ListNode* head, int k)
    {
        int length = linkLength(head);
        if (length == 0)
            return head;

        // 找出 new end node 
        k = k % length;
        int nodeIndex = length - k - 1;
        ListNode *newEnd = head;
        while(nodeIndex > 0)
        {
            newEnd = newEnd->next;
            nodeIndex--;
        }
        // 若 new end node 跟原本一樣，代表不用 rotate
        if (newEnd->next == nullptr)
            return head;

        
        // 找出 end node 和 new head
        ListNode *newHead = newEnd->next;
        ListNode *end = newEnd;
        while(end->next != nullptr)
            end = end->next;

        // 將 new end node 指向 nullptr
        newEnd->next = nullptr;

        // 將 end 指向 head
        end->next = head;
        return newHead;
    }
};