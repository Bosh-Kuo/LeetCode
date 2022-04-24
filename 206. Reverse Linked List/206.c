/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* reverseList(struct ListNode* head){
    struct ListNode* end = NULL;
    struct ListNode* reverse = NULL;
    struct ListNode* current = head;
    while(current != NULL)
    {
        reverse = current;
        current = current -> next;
        reverse -> next = end;
        end = reverse;
    }
    return reverse;
}