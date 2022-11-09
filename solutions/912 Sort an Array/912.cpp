/*
time complexity: O(nlog(n))
tags: Array, Divide and Conquer, Sorting, Heap(Priority Queue), Merge Sort, Bucket Sort, Radix Sort, Counting Sort
note: 標準 Merge Sort 作法
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    void merge(vector<int> &nums, int left, int mid, int right)
    {

        int arraySize = right - left + 1;
        vector<int> tmp(arraySize);
        int leftCursor = left;
        int rightCursor = mid + 1;
        int tmpCursor = 0;
        while (leftCursor <= mid || rightCursor <= right)
        {
            int leftNum = leftCursor <= mid ? nums[leftCursor] : 1000000;
            int rightNum = rightCursor <= right ? nums[rightCursor] : 1000000;
            if (leftNum <= rightNum)
            {
                tmp[tmpCursor] = leftNum;
                tmpCursor++;
                leftCursor++;
            }
            else
            {
                tmp[tmpCursor] = rightNum;
                tmpCursor++;
                rightCursor++;
            }
        }

        for (int i = 0; i < arraySize; i++)
            nums[left + i] = tmp[i];
    }

    void mergeSort(vector<int> &nums, int left, int right)
    {
        if (left >= right)
            return;
        int mid = (left + right) / 2;
        mergeSort(nums, left, mid);      // divide into left sub array
        mergeSort(nums, mid + 1, right); // divide into right sub array
        merge(nums, left, mid, right);   // combine
    }

    vector<int> sortArray(vector<int> &nums)
    {
        mergeSort(nums, 0, nums.size() - 1);
        return nums;
    }
};

int main()
{
    vector<int> nums = {5, 1, 1, 2, 0, 0};
    Solution sol;
    nums = sol.sortArray(nums);

    for (auto num : nums)
        cout << num << " ";
}