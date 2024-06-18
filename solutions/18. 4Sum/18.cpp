/*
time complexity : O(n^3)
tags: Array, Two Pointers, Sorting
note: 用兩個 nested loop 固定最左跟最右的數值，在這兩個數值之件再用 two pointers (1 loop)來選剩下的兩個數
*/

class Solution
{
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        set<vector<int>> quadrupletSet;

        // 確保最左最右之劍至少空兩格
        for (int i = 0; i <= n - 4; i++)
        {
            for (int j = n - 1; j >= i + 3; j--)
            {
                // 固定最左與最右的兩個數，在兩者之間用 2 pointers 尋找符合條件的另外兩個數
                int left1 = nums[i], right1 = nums[j];
                int low = i + 1, high = j - 1;

                long long newTarget = (long long)target - left1 - right1;
                while (low < high)
                {
                    int left2 = nums[low], right2 = nums[high];
                    if (left2 + right2 == newTarget)
                    {
                        quadrupletSet.insert({left1, left2, right2, right1});
                        low++;
                        high--;
                    }
                    else if (left2 + right2 > newTarget)
                    {
                        high--;
                    }
                    else
                    {
                        low++;
                    }
                }
            }
        }
        for (auto it : quadrupletSet)
        {
            ans.push_back(it);
        }
        return ans;
    }
};
