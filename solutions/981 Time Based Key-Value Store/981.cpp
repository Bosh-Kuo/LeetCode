/*
time complexity: O(n)
tags: Hash Table, String, Binary Search, Design
note: 使用 unordered_map 存 map，因為 map 有排序，所以使用反向迭代器遍歷時，會根據 key 由大到小訪問
*/

class TimeMap
{
private:
    unordered_map<string, map<int, string>> timeMap;

public:
    TimeMap()
    {
    }

    void set(string key, string value, int timestamp)
    {
        timeMap[key][timestamp] = value;
    }

    string get(string key, int timestamp)
    {
        if (timeMap.find(key) != timeMap.end() && (timeMap[key].begin())->first <= timestamp)
        {
            // 從 timeMap[key] 的末尾反向遍歷
            for (auto it = timeMap[key].rbegin(); it != timeMap[key].rend(); it++)
            {
                if (it->first <= timestamp)
                    return it->second;
            }
        }
        return "";
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */