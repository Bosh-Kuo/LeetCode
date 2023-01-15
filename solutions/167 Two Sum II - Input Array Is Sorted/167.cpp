/*
time complexity: O(nlog(n))
tags: Array, Two Pointers, Binary Search
note: 由於此題只能用 constant extra space， 因此不能用 hash table 來記錄。本題用 Binary Search 逐一檢查每個 index 是否存在可組合成 target 的組合
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int binarySearch(vector<int> &numbers, int left, int right, int target)
    {
        while (right >= left)
        {
            int mid = (left + right) / 2;
            if (numbers[mid] > target)
                right = mid - 1;
            else if (numbers[mid] < target)
                left = mid + 1;
            else
                return mid;
        }
        return -1;
    }
    vector<int> twoSum(vector<int> &numbers, int target)
    {
        vector<int> Ans;
        for (int i = 0; i < numbers.size() - 1; i++)
        {
            int index2 = binarySearch(numbers, i + 1, numbers.size() - 1, target - numbers[i]);
            if (index2 != -1)
            {
                Ans.push_back(i + 1);
                Ans.push_back(index2 + 1);
                return Ans;
            }
        }
        return Ans;
    }
};

int main()
{
}