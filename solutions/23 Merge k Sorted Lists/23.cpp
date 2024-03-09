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

/*
解法一： Compare K elements One By One
time complexity: O(k*K), k = lists.length, K = # of elements
tags: Linked List, Divide and Conquer, Heap(Priority Queue), Merge Sort
note: 重複遍歷 lists，挑出最小的 node 接在 answerList 後，若最小 node 已經是該 list 中最後一個，則移除該 list
直到 lists 為空為止
*/
class Solution
{
public:
    void removeEmptyList(vector<ListNode *> &lists)
    {
        int idx = 0;
        while (idx < lists.size())
        {
            if (lists[idx] == nullptr)
                lists.erase(lists.begin() + idx);
            else
                idx++;
        }
    }
    int findMinListIdx(vector<ListNode *> &lists)
    {
        int idx = 0;
        // 由於每個 list 都已被排序好，所以每個 list 的 head 一定是最小的
        for (int i = 1; i < lists.size(); i++)
        {
            if (lists[i]->val < lists[idx]->val)
                idx = i;
        }
        return idx;
    }

    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        // 1. 清除空 list
        removeEmptyList(lists);

        // 2. 若 lists 為空，直接返回
        if (lists.size() == 0)
            return nullptr;

        // 3. 建立一個  answerList，並將 dummy head 作為最初的 node
        ListNode *dummyHead = new ListNode(0);
        ListNode *answerList = dummyHead;

        // 4. 重複遍歷 lists，挑出最小的 node 接在 answerList 後
        while (lists.size() > 0)
        {
            // 挑出 lists 中最小的 node 接在 answerList 後面
            int minListIdx = findMinListIdx(lists);
            ListNode *minNode = lists[minListIdx];
            answerList->next = minNode;
            answerList = answerList->next;

            // 若最小 node 已經是該 list 中最後一個，則移除該 list
            // 否則將最小 node 的來源 list 改為最小 node 原本的下一個 node
            if (lists[minListIdx]->next == nullptr)
                lists.erase(lists.begin() + minListIdx);
            else
                lists[minListIdx] = lists[minListIdx]->next;
        }

        return dummyHead->next;
    }
};

/*
解法二： Divide & Conquer
time complexity: O(K*log(k)), k = lists.length, K = # of elements
tags: Linked List, Divide and Conquer, Heap(Priority Queue), Merge Sort
note: 用 Divide & Conquer 兩兩 merge
*/
class Solution
{
public:
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        if (lists.size() == 0)
            return NULL;
        return mergeTwoLists(lists, 0, lists.size() - 1);
    }

    ListNode *mergeTwoLists(vector<ListNode *> &lists, int start, int end)
    {
        if (start > end)
            return NULL;
        if (start == end)
            return lists[start];

        int mid = start + (end - start) / 2;
        ListNode *leftList = mergeTwoLists(lists, start, mid);
        ListNode *rightList = mergeTwoLists(lists, mid + 1, end);
        return merge(leftList, rightList);
    }

    ListNode *merge(ListNode *leftList, ListNode *rightList)
    {
        ListNode *dummyHead = new ListNode(-1);
        ListNode *mergedList = dummyHead;

        while (leftList != NULL && rightList != NULL)
        {
            if (leftList->val < rightList->val)
            {
                mergedList->next = leftList;
                leftList = leftList->next;
            }
            else
            {
                mergedList->next = rightList;
                rightList = rightList->next;
            }
            mergedList = mergedList->next;
        }
        mergedList->next = (leftList != NULL) ? leftList : rightList;
        return dummyHead->next;
    }
};