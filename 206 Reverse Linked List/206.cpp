/*
time complexity: O(n)
tags: Linked List, Recursion
note: 目標以 recursion 取得最後一個 node 並反轉 node 前後的指向。在 ascending state 一路轉換指標方向，在 descending state 一路將終止條件的 node 一路傳回來
*/

#include <iostream>
using namespace std;

//  Definition for singly-linked list.
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
    ListNode *reverseList(ListNode *head)
    {
        if (head == nullptr)
            return head;
        else
            return recursive_swap(head, head->next);
    }

    ListNode *recursive_swap(ListNode *front, ListNode *back)
    {
        // 終止條件：back 為 null 表示 front 為 link list 中的最後一個 node 了
        if (back == nullptr)
            return front;
        // 取得下一個 pair 的 back
        ListNode *backNext = back->next;
        // 娑 front->next 為 back 表示 front 為 link list 中的第一個 node（沒有當過 back）
        if (front->next == back)
            front->next = nullptr;
        back->next = front;
        return recursive_swap(back, backNext);
    }
};

int main()
{
    ListNode node4 = ListNode(4);
    ListNode node3 = ListNode(3, &node4);
    ListNode node2 = ListNode(2, &node3);
    ListNode node1 = ListNode(1, &node2);
    Solution sol;
    ListNode *head = sol.reverseList(&node1);
    ListNode *ptr = head;
    while (ptr != nullptr)
    {
        cout << ptr->val << endl;
        ptr = ptr->next;
    }
    return 0;
}