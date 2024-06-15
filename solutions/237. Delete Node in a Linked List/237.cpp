/*
time complexity: O(n)
tags: Linked List
note: 從欲移除的 node 開始，將 value 替換成 next->value，原本倒數第二個 node 則改指向 nullptr
*/

#include <iostream>
using namespace std;

class Solution {
public:
    void deleteNode(ListNode* node) {
        while(node!=nullptr)
        {                    
            node->val = node->next->val;
            if (node->next->next == nullptr)
                node->next = nullptr;   
            node = node->next;
        }
    }
};