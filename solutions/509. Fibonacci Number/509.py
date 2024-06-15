"""
time complexity: O(n)
tags: Math, Dynamic Programming, Recursion, Memorization
note: 用 Recursion 姐雖然比較直覺但是會有重複計算的問題，
像是 fib(5) = fib(4) + fib(3), fib(5) = fib(3) + fib(2)，fib(3) 被 call 兩次
用 iterator 解可以避免重複計算
"""


class Solution:
    def fib(self, n: int) -> int:
        if n == 0:
            return 0
        elif n == 1:
            return 1
        else:
            fib_prev = 0
            fib_current = 1
            for i in range(2, n+1):
                fib_next = fib_prev + fib_current
                fib_prev = fib_current
                fib_current = fib_next
            return fib_current
