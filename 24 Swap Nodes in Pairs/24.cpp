/*
time complexity: O(n)
tags: Linked List, Recursion
note: 兩兩 nodes 值互換，每前進兩步，直到無法前進為止
*/

#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *swapPairs(ListNode *head)
    {
        swap_one_pair(head);
        return head;
    }
    void swap_one_pair(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr)
            return;
        // swap pair
        int temp = head->val;
        head->val = head->next->val;
        head->next->val = temp;
        // go to swap next pair
        swap_one_pair(head->next->next);
    }
};

int main()
{
    ListNode node4 = ListNode(4);
    ListNode node3 = ListNode(3, &node4);
    ListNode node2 = ListNode(2, &node3);
    ListNode node1 = ListNode(1, &node2);
    Solution sol;
    ListNode *head = sol.swapPairs(&node1);
    // ListNode *head = &node1;
    ListNode *ptr = head;
    while(ptr!=nullptr)
    {
        cout << ptr->val << endl;
        ptr = ptr->next;
    }
}