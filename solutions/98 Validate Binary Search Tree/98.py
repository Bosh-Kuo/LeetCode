"""
time complexity: O(n)
tags: Tree, Depth-First Search, Binary Search Tree, Binary Tree
note: 當前的節點對左子樹來說必是最大值，當前的節點對右子樹來說必是最小值。用 DFS 從 left node 開始檢查。
node 的 left child 必須小於該 node，node 的 right child 必須大於該 node，
若 node 的任一子樹回傳為 False ，便向 parent node 回傳 False
"""
# Definition for a binary tree node.
from math import inf
from typing import Optional


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def isValidBST(self, root: Optional[TreeNode]) -> bool:
        def helper(node: Optional[TreeNode], low: int, high: int) -> bool:
            if node is None:
                return True
            if node.val >= high or node.val <= low:
                return False
            else:
                # 該 node 的左右子樹的檢查結果都為 True 才向 parent node 回傳 True
                return helper(node.left, low, node.val) and helper(node.right, node.val, high)

        return helper(root, -inf, inf)
