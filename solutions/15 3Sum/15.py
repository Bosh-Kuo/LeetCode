"""
time complexity : O(n^2)
tags: Array, Two Pointers, Sorting
note: 先將 Array 從小到大排序好，以 Loop 取 nums[i] 作為固定值，取 i 右側最近與最遠的 element 作為 Two Pointers 起點
觀察 nums[i] + left + right:
= 0 則加入答案組中
> 0 : right pointer 向左走
< 0 : left pointer 向右走
"""


from typing import List


class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        ans = []
        nums.sort()
        for i in range(len(nums) - 2):
            # 跟前面一個 element 重複時就跳過
            if (i > 0 and nums[i] == nums[i - 1]):
                continue

            # 當最前面的 element 都大於 0 了，後面的 element 肯定也會大於 0
            if (nums[i] > 0):
                break

            left = i + 1
            right = len(nums) - 1
            while(left < right):
                sum = nums[i] + nums[left] + nums[right]
                if(sum == 0):
                    if((left > i + 1 and nums[left] == nums[left-1]) or (right < len(nums) - 1 and nums[right] == nums[right+1])):
                        left += 1
                        right -= 1
                    else:
                        ans.append([nums[i], nums[left], nums[right]])
                        left += 1
                        right -= 1
                elif(sum < 0):
                    left += 1
                else:
                    right -= 1
        return ans
