/*
time complexity : O(m+n)
tags: Array, Two Pointers, Sorting
note: 從 nums1 與 nums2 的最大值開始比，較大者指針向前走ㄧ格並且填入 num1 的末端

*/

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // 從 nums1, nums2 最大的開始比
        int idx1 = m - 1, idx2 = n - 1;
        for (int i = m + n - 1; i >= 0; i--)
        {
            // 若 nums1 全部都比過，直接填 nums2 的元素
            if(idx1 < 0)
            {
                nums1[i] = nums2[idx2];
                idx2--;
            }
            // 若 nums2 全部都比過，直接填 nums1 的元素
            else if (idx2 < 0)
            {
                nums1[i] = nums1[idx1];
                idx1--;
            }
            else
            {
                // 若 nums1 的元素比較大則填入 nums1 的元素
                if(nums1[idx1] >= nums2[idx2])
                {
                    nums1[i] = nums1[idx1];
                    idx1--;
                }
                else
                {
                    nums1[i] = nums2[idx2];
                    idx2--;
                }
            }
        }
        
    }
};