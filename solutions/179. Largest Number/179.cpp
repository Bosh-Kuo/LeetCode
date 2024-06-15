/**
time complexity: O(n*log(n))
tags: Array, String, Greedy, Sorting
note: 自訂義比較函數，讓 nums 的排序結果可串接成最大數字。排序規則為：兩數能組成最大數字者排前面
*/

class Solution
{
public:
    static bool comp(const int &a, const int &b)
    {
        string a_str = to_string(a);
        string b_str = to_string(b);
        return a_str + b_str > b_str + a_str;
    }
    string largestNumber(vector<int> &nums)
    {
        sort(nums.begin(), nums.end(), comp);
        if (nums[0] == 0)
            return "0";

        string ans = "";
        for (auto num : nums)
            ans += to_string(num);

        return ans;
    }
};