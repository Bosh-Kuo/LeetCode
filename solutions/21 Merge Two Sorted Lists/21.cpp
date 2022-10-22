/*
time complexity: O(n)
tags: Linked List, Recursion
note: 從兩 list 中挑出最小的 node 作為 head，後面接著排除掉該 node 後透過 mergeTwoLists 排序好的 sorted list，
透過 recursion 逐步縮小傳入 mergeTwoLists 的 list 長度。當其中有一個 list 為 nullptr 時，帶嫑此時傳進來的兩個 list 排序好的結果就是非 nullptr 的另一個 list
*/

#include <iostream>
using namespace std;

// Definition for singly-linked list.
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
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        if (list1 == nullptr && list2 == nullptr)
            return nullptr;
        if (list1 == nullptr)
            return list2;
        if (list2 == nullptr)
            return list1;
        ListNode *smallerNode = (list1->val <= list2->val) ? list1 : list2;
        ListNode *largerNode = (list1->val <= list2->val) ? list2 : list1;
        smallerNode->next = mergeTwoLists(smallerNode->next, largerNode);
        return smallerNode;
    }
};

int main()
{
    ListNode node_1_4 = ListNode(4);
    ListNode node_1_2 = ListNode(2, &node_1_4);
    ListNode node_1_1 = ListNode(1, &node_1_2);
    ListNode node_2_4 = ListNode(4);
    ListNode node_2_3 = ListNode(3, &node_2_4);
    ListNode node_2_1 = ListNode(1, &node_2_3);
    Solution sol;
    ListNode *sortedList = sol.mergeTwoLists(&node_1_1, &node_2_1);
    while (sortedList != nullptr)
    {
        cout << sortedList->val << " ";
        sortedList = sortedList->next;
    }
    

}