#include <stdio.h>
#include <stdlib.h>

// Definition for singly-linked list.
typedef struct ListNode
{
    int val;
    struct ListNode *next;
} ListNode;

ListNode *removeNthFromEnd(ListNode *head, int n)
{
    ListNode *dummyhead = (ListNode *)malloc(sizeof(ListNode));
    dummyhead->next = head;
    ListNode *fast = dummyhead;
    ListNode *slow = dummyhead;
    while (n > 0 && fast != NULL)
    {
        fast = fast->next;
        n -= 1;
    }
    fast = fast->next;  // 讓 fast 比 slow 多 n+1 步， 當 fast 走到 tail 後的 NULL時，slow->next 就是要刪除的 Node
    while(fast != NULL)
    {
        fast = fast->next;
        slow = slow->next;
    }
    slow->next = slow->next->next;
    return dummyhead->next;
}

