/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* reverseBetween(struct ListNode* head, int left, int right){
    struct ListNode dummyNode = {0, head};
    struct ListNode* dummyHead = &dummyNode;
    struct ListNode* beforeReverse = dummyHead;
    
    // 找到開始 reverse 前的 Node
    for(int i = 0; i < left-1; i++)
        beforeReverse = beforeReverse->next;
    
    // reverse 後的最後一個 Node
    struct ListNode* reverseEnd = beforeReverse->next;
    // 處理 reverse 當前的 Node
    struct ListNode* reverseCurrent = reverseEnd;
    // 處理 reverse 當前要接上的 Node
    struct ListNode* reverse = NULL;
    for (int i = 0; i <= (right - left); i++)
    {
        struct ListNode* next = reverseCurrent->next;
        reverseCurrent->next = reverse;
        reverse = reverseCurrent;
        reverseCurrent = next;
    }
    beforeReverse->next = reverse;
    reverseEnd->next = reverseCurrent;
    return dummyNode.next;
}
