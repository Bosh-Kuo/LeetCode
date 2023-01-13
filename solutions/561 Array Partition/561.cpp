/*
time complexity: O(nlog(n))
tags: Array, Greedy, Sorting, Counting Sort
note: 若要兩兩一組取其中小值來加總出最大的結果，就必須讓大數與大數組在一起，小數與小數組在一起，也就是 sorting，sorting 後的偶數位置極為最佳組合
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int arrayPairSum(vector<int> &nums)
    {
        int ans = 0;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++)
        {
            if (i % 2 == 0)
                ans += nums[i];
        }
        return ans;
    }
};
int main()
{
}