/*
time complexity: O(n)
tags: Array
note: 先算出 nums 的加總，接著從 idx = 0 開始累積計算左半邊的總和，該位置的 score 即為 (i - 左半邊總合) + (sum - 左半邊總合)。
最後再挑出 score 最大的 位置。
*/

#include <numeric>
#include <algorithm>
#include <iostream>
#include <vecotor>
using namespace std;

class Solution
{
public:
    vector<int> maxScoreIndices(vector<int> &nums)
    {
        vector<int> Ans;
        vector<int> score(nums.size() + 1, 0);
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int left_accumulation = 0;
        for (int i = 0; i < score.size(); i++)
        {
            if (i - 1 >= 0)
                left_accumulation = left_accumulation + nums[i-1];
        
            int left = i - left_accumulation;
            int right = sum - left_accumulation;
            score[i] = left + right;
        }
        int max = *max_element(score.begin(), score.end());
        for (int i = 0; i < score.size(); i++)
        {
            if (max == score[i])
                Ans.push_back(i);
        }
        return Ans;
    }
};

int main()
{
}