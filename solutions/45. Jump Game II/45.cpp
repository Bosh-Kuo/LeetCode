/*
time complexity : O(n)
tags: Array, Dynamic Programming, Greedy
note: 紀錄所能到達的最遠位置，當走到後則更新目前前進所花費最小的步數，以及下一個能在最小步數下到達的最遠位置
*/

class Solution
{
public:
    int jump(vector<int> &nums)
    {
        int ans = 0;
        int visitedFarthest = 0;
        int farthest = 0;

        for (int i = 0; i < nums.size() - 1; ++i)
        {
            // 預計可到達的最遠位置
            int farthest = max(farthest, i + nums[i]);
            // 若可到達的最遠位置已超過 nums 長度，直接回傳
            if (farthest >= nums.size() - 1)
            {
                ++ans;
                break;
            }
            // 若已走到了過去所能到達的最遠位置，則更新目前所能到達的最遠位置
            if (i == visitedFarthest)
            {
                ++ans;
                visitedFarthest = farthest;
            }
        }

        return ans;
    }
};