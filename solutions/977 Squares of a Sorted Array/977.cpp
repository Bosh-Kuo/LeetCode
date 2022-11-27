/*
time complexity : O(nlog(n))
tags: Array
note: 用 sort 函數排序 vector
*/

#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> Ans;
        for(auto num: nums)
            Ans.push_back(num*num);
        sort(Ans.begin(), Ans.end());
        return Ans;
    }
};