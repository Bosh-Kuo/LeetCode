/*
time complexity: O(n)
tags: Array, Sorting
note: 找出最大值再一個一個比
*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
    int dominantIndex(vector<int> &nums)
    {
        int max = *max_element(nums.begin(), nums.end());
        int Ans = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (max == nums[i])
                Ans = i;

            else 
                if (max < nums[i] * 2)            
                    return -1;            
        }
        return Ans;
    }
};

int main()
{
}