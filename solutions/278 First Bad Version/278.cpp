/*
time complexity: O(log(n))
tags: Binary Search, Interactive
note: 用 Binary Search 來找： isBadVersion(i) is true, isBadVersion(i-1) is false
*/

// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution
{
public:
    int binarySearch(int left, int right)
    {
        if (left >= right)
            return left;
        int mid = left + (right - left) / 2;
        if (isBadVersion(mid) && !isBadVersion(mid - 1))
            return mid;
        else if (isBadVersion(mid))
            return binarySearch(left, mid - 1);
        else
            return binarySearch(mid + 1, right);
    }

    int firstBadVersion(int n)
    {
        if (isBadVersion(1))
            return 1;
        // Binary Search : find index i which isBadVersion(i) is true, isBadVersion(i-1) is false
        return binarySearch(2, n);
    }
};