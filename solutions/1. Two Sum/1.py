'''
time complexity : O(n)
tags: Array, Hash Table
note: 用 Hash Table 存下已經看過的數字作為 key，index 作為 value，當 target - 當前的數字有存在 Table 中就可以直接拿來用
'''


from typing import List


class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        hashTable = {}
        for i in range(len(nums)):
            if target - nums[i] in hashTable:
                return [i, hashTable[target - nums[i]]]    
            else:
                hashTable[nums[i]] = i
