/**
time complexity: O(n)
tags: Array, Two Pointers, Binary Search, Bit Manipulation
note: 若一個數字既一定會在 index 的合理範圍內，那麼把數字作為 index 就會出現兩次或以上指向同的元素，
第一次指向元素時將該元素轉負(做上記號)，只要遇到複數就代表這個 index 之前出現過
*/

class Solution
{
public:
    int findDuplicate(vector<int> &nums)
    {
        for (auto num : nums)
        {
            int idx = abs(num);
            // 若 nums[idx] 小於 0，表示 idx 已經出現過了
            if (nums[idx] < 0)
                return idx;

            nums[idx] = -nums[idx];
        }

        return 0;
    }
};