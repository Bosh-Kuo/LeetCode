/*
time complexity: O(n)
tags: Array, Math, Binary Search, Prefix Sum, Randomized
note: 將 w[i] 的 prefix sum 存起來，舉例來說 w = [2,3,5] => prefixSum = [2,5,10]
隨機取得 [0, prefixSum.back()) 的亂數，使用 upper_bound 即可取得亂數對應的 index
當亂數範圍在 [0,2) upper_bound 對應的 index 為 0
當亂數範圍在 [2,5) upper_bound 對應的 index 為 1
當亂數範圍在 [5,10) upper_bound 對應的 index 為 2
*/

class Solution
{
private:
    vector<int> nums;

public:
    Solution(vector<int> &w)
    {
        nums.push_back(w[0]);
        for (int i = 1; i < w.size(); i++)
        {
            nums.push_back(nums.back() + w[i]);
        }
    }

    int pickIndex()
    {
        int random = rand() % nums.back();
        auto it = upper_bound(nums.begin(), nums.end(), random);
        return it - nums.begin();
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */