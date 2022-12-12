/*
time complexity: O(n)
tags: Array, Hash Table, Prefix Sum
note: 用 unordered_map 作為 hash map， 以每個 index 的 prefix sum 為 key，該 prefix sum 出現次數為 value，並且儲存一 prefix array，當 prefix[i] - target 為 hash map 的其中一個 key，
代表某個比 i 小的 index j 其 prefix sum 為 prefix[j] = prefix[i] - target，使得 prefix[i] - prefix[j] = target，而 hash map 中以 prefix[i] - target 為 key 對應到的 value 則為 prefix[i] - target
作為前面的 prefix sum 出現的次數
*/

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    int subarraySum(vector<int> &nums, int k)
    {
        vector<int> prefixSum;
        unordered_map<int,int> hashMap;
        int count = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (i == 0)
                prefixSum.push_back(nums[i]);
            else
                prefixSum.push_back(nums[i]+prefixSum[i-1]);
        }

        // 任何元素都不取時 prefix sum 為 0
        hashMap[0] = 1;
        for (int i = 0; i < prefixSum.size(); i++)
        {
            // 當 prefixSum[i] - k 有記錄在 hash map 中，就加上 prefixSum[i] - k 出現的次數
            if(hashMap.count(prefixSum[i] - k))
                count += hashMap[prefixSum[i] - k];
            
            // 將 prefixSum[i] 加入 hash map
            hashMap.count(prefixSum[i]) ? hashMap[prefixSum[i]] += 1 : hashMap[prefixSum[i]] = 1;
        }
        return count;
    }
};

int main()
{
    vector<int> nums = {0,1,1};
    int k = 2;
    Solution sol;
    cout << sol.subarraySum(nums, k);
}