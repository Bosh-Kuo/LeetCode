"""
time complexity : O(n)
tags: Linked List, Two Pointers
note: 讓 fast 先站在第 n 個位置，再讓 slow 從 dummy 開始與 fast 一起前進，當 fast.next 為 None 時，
刪除 slow 的下一個 node
"""


from typing import Optional

# Definition for singly-linked list.


class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
        dummy = ListNode(next=head)
        faster = head
        slow = dummy
        while(n-1 > 0):
            faster = faster.next
            n -= 1

        while(faster.next is not None):
            faster = faster.next
            slow = slow.next
        
        slow.next = slow.next.next
        return dummy.next
