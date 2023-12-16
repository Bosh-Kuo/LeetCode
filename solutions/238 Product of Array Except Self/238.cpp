/*
time complexity: O(n)
tags: Array, Prefix Sum
note: 如果 nums 裡面有超過一個 0，那 answer 一定全部都是 0，如果 nums 裡有一個 0，那要為這個 0 特別計算除了 0 外其他數的總乘積
*/

class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        int productOfAllWithout0 = 1;
        int productOfAllWith0 = 0;
        int zeroCount = 0;
        vector<int> answer(nums.size(), 0);
        for (auto num : nums)
        {
            if (num == 0)
                zeroCount += 1;
            else
                productOfAllWithout0 *= num;
        }
        // 如果 nums 裡面有超過一個 0，那 answer 一定全部都是 0
        if (zeroCount > 1)
            return answer;
        else
        {
            for (int i = 0; i < nums.size(); i++)
            {
                //  nums 裡有一個 0
                if (zeroCount == 1)
                    answer[i] = nums[i] == 0 ? productOfAllWithout0 : productOfAllWith0;
                //  nums 裡沒有 0
                else
                    answer[i] = productOfAllWithout0 / nums[i];
            }
        }

        return answer;
    }
};