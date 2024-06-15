/*
time complexity: O(n)
tags: Array, Binary Search, Sliding Window, Prefix Sum
note: 使用 Two Pointers，一個 Pointer 指向滿足條件的 sub-array 的起點，一個 Pointer 指向滿足條件的 sub-array 的終點，
紀錄尋找滿足條件的 sub-array 的過程中，兩個 Pointer 最小的間距
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int minSubArrayLen(int target, vector<int> &nums)
    {
        vector<int> prefix;
        int pointer1 = 0, pointer2 = 0, minLength = 0;

        for (int i = 0; i < nums.size(); i++, pointer2++)
        {
            // prefix sum
            if (i == 0)
                prefix.push_back(nums[i]);
            else
                prefix.push_back(prefix[i - 1] + nums[i]);

            // two pointers
            while (pointer1 <= pointer2 && prefix[pointer2] - prefix[pointer1] + nums[pointer1] >= target)
            {
                int length = pointer2 - pointer1 + 1;
                if (minLength == 0 || (minLength != 0 && length <= minLength))
                    minLength = length;
                pointer1++;
            }
        }
        return minLength;
    }
};

int main()
{
}
