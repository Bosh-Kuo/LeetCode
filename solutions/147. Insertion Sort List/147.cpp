/**
time complexity: O(n^2)
tags:  Sorting, Linked
note: 看成新的排序串列與當前要插入排序串列的節點的 insert 問題，在 insert 的同時維護著排序串列的順序，直到所有節點都處理完成
 */

class Solution
{
public:
    ListNode *insertionSortList(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr)
        {
            return head; // 當串列為空或只有一個節點時，不需排序，直接返回
        }

        ListNode *newHead = nullptr; // 新的排序串列的頭部
        ListNode *current = head;    // 目前處理的節點

        while (current != nullptr)
        {
            ListNode *next = current->next; // 下一個要處理的節點

            if (newHead == nullptr || current->val < newHead->val)
            {
                // 如果新的排序串列為空，或者目前節點的值小於新排序串列的頭部值
                current->next = newHead;
                newHead = current; // 更新新排序串列的頭部
            }
            else
            {
                // 否則，找到適當的位置插入節點
                ListNode *search = newHead;
                while (search->next != nullptr && search->next->val <= current->val)
                {
                    search = search->next;
                }
                current->next = search->next;
                search->next = current;
            }

            current = next; // 移動到下一個待處理的節點
        }

        return newHead;
    }
};
