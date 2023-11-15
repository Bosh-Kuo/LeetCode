/*
time complexity: O(nlogn)
tags: Array, Hash Table,  Divide and Conquer, Sorting, Heap(Priority Queue), Bucket Sort, Counting, Quickselect
note: 用 Hash Table 記下所有數字出現的次數，接著將這些紀錄塞進 priority queue，再從 priority queue 裡 pop 出現次數最大的前 K 個
*/

class Solution
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {

        priority_queue<pair<int, int>> bigestK;
        unordered_map<int, int> hashTable;
        vector<int> answer;

        for (auto i : nums)
        {
            hashTable[i]++;
        }
        for (auto i : hashTable)
        {
            bigestK.push({i.second, i.first});
        }

        // 將 bigestK 記錄下的前Ｋ常出現的數 push 到 vector
        while (k > 0 && !bigestK.empty())
        {
            answer.push_back(bigestK.top().second);
            bigestK.pop();
            k--;
        }

        return answer;
    }
};