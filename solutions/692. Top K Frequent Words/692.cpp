/*
time complexity: O(n*log(k))
tags: Hash Table, String, Trie, Sorting, Heap(Priority Queue), Bucket Sort, Counting
note: 用 hash map 紀錄每個 word 出現的次數，並用自定義 max heap 儲存字串與出現字數，並定義 max heap 比較規則
*/

struct MaxHeapComparator
{
    bool operator()(pair<string, int> lhs, pair<string, int> rhs)
    {
        if (lhs.second < rhs.second)
            return true;
        else if (lhs.second > rhs.second)
            return false;
        else
            return lhs.first > rhs.first;
    }
};

class Solution
{
public:
    vector<string> topKFrequent(vector<string> &words, int k)
    {
        vector<string> ans;

        // hash map 紀錄每個 word 出現的次數
        unordered_map<string, int> hashMap;
        for (auto word : words)
        {
            hashMap[word]++;
        }

        // 自定義 max heap 取得前 k words
        priority_queue<pair<string, int>, vector<pair<string, int>>, MaxHeapComparator> maxHeap;
        for (auto it = hashMap.begin(); it != hashMap.end(); ++it)
        {
            maxHeap.push({it->first, it->second});
        }

        for (int i = 0; i < k; i++)
        {
            ans.push_back(maxHeap.top().first);
            maxHeap.pop();
        }

        return ans;
    }
};