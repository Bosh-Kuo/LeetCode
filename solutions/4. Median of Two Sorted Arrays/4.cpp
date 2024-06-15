/*
time complexity: O(log(n+m))
tags: Array, Binary Search, Divide And Conquer
note: 將兩 array 聯合起來分成左半與右半。
當 total 為奇數時，左半的數量為 (total+1)/2， max(l1, l2) 即為中位數
當 total 為偶數時，左半的數量為 total/2， (max(l1,l2) + min(r1,r2))/2 即為中位數
exp:
[1,2,3|4,5,6,7]
[1,2,3|4]

[3|4,5,6,7]
[1,2,3,4|5]
參考： https://leetcode.com/problems/median-of-two-sorted-arrays/solutions/4070500/99-journey-from-brute-force-to-most-optimized-three-approaches-easy-to-understand/?envType=list&envId=p6idgg6t
*/

class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        // 確保 m >= n (nums2 比較短)
        int m = nums1.size(), n = nums2.size();
        if (n > m)
            return findMedianSortedArrays(nums2, nums1);

        int total = n + m;
        int numOfLeft = (total + 1) / 2; // 左半側所需的元數個數

        // 極端狀況
        if (n == 0)
            return total % 2 == 0 ? (nums1[total / 2 - 1] + nums1[total / 2]) / 2.0 : nums1[total / 2];

        int left2 = 0, right2 = n;
        while (left2 <= right2)
        {
            int cut2 = (left2 + right2) / 2;
            int cut1 = numOfLeft - cut2;

            int l1 = INT_MIN, l2 = INT_MIN, r1 = INT_MAX, r2 = INT_MAX;
            if (cut1 < m)
                r1 = nums1[cut1];
            if (cut2 < n)
                r2 = nums2[cut2];
            if (cut1 - 1 >= 0)
                l1 = nums1[cut1 - 1];
            if (cut2 - 1 >= 0)
                l2 = nums2[cut2 - 1];

            if (l1 <= r2 && l2 <= r1)
            {
                // The partition is correct, we found the median
                if (total % 2 == 1)
                    return max(l1, l2);
                else
                    return (max(l1, l2) + min(r1, r2)) / 2.0;
            }

            else if (l2 > r1)
            {
                // Move towards the left side of nums2
                right2 = cut2 - 1;
            }
            else
            {
                // Move towards the right side of nums1
                left2 = cut2 + 1;
            }
        }
        return 0;
    }
};
