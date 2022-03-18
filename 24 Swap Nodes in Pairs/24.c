#include <stdio.h>
#include <stdlib.h>

// step1: fakehead -> N1 -> N2 -> N3 -> N4
// step2: fakehead -> N2 -> N1 -> N3 -> N4
// step3: fakehead -> N2 -> N1 -> N4 -> N1



//  Definition for singly-linked list.
 struct ListNode {
     int val;
     struct ListNode *next;
 };


struct ListNode* swapPairs(struct ListNode* head){
    typedef struct ListNode ListNode;
    ListNode *dummyHead = (ListNode*)malloc(sizeof(ListNode));
    dummyHead->next = head;
    ListNode *cur = dummyHead;
    
    while(cur->next != NULL && cur->next->next != NULL)
    {
        ListNode *curNext = cur->next;  // N1
        ListNode *curNext3 = cur->next->next->next;  // N3

        cur->next = curNext->next;  // fakehead -> N2
        ListNode *newCurNext = cur->next;  // N2
        newCurNext->next = curNext;  // N2 -> N1
        newCurNext->next->next = curNext3;  // N1 -> N3

        // fakehead -> N2 -> N1 -> N3 -> N4
        cur = cur->next->next;  // N1
    }
    return dummyHead->next;
}