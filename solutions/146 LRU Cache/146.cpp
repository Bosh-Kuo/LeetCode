/**
time complexity: O(n)
tags: Hash Table, Linked List, Design, Doubly-Linked List
note: 用一個 doubly-linked list 紀錄 key，排前面表示近期有使用到。用 hashmap 紀錄 key -> (key's address in keyList, value)
Get:
搜尋 hashmap，找不到 => 回傳 -1； 找得到 => 回傳 value，並把 keyList 中紀錄的 key 移到最前面

Push:
若 hashmap 有存此 key => 回傳 value 並把 keyList 中紀錄的 key 移到最前面
若 hashmap 沒有存此 key => 在 hashmap 添加此 {key, {keyList.begin(), value}}
若 capacity < 0 => 移除 keyList 最後的 key 以及 hashmap 中該 key 的 pair
*/

class LRUCache
{
private:
    // 將 key 移除從 keyList 移除，再加到最前面，並更新 hashmap 中該 key 的 address
    void moveKeyToFront(int key)
    {
        keyList.erase(hashmap[key].first);
        keyList.push_front(key);
        hashmap[key].first = keyList.begin();
    }

public:
    int capacity;
    list<int> keyList;                                          // 用排序來記錄 key 的使用紀錄，排前面表示近期有使用到
    unordered_map<int, pair<list<int>::iterator, int>> hashmap; // 紀錄 key, (key's address in keyList, value)
    LRUCache(int capacity)
    {
        this->capacity = capacity;
    }

    int get(int key)
    {
        // 找不到 => 回傳 -1
        if (hashmap.find(key) == hashmap.end())
            return -1;
        else
        {
            moveKeyToFront(key);
            return hashmap[key].second;
        }
    }

    void put(int key, int value)
    {
        if (hashmap.find(key) == hashmap.end())
        {
            keyList.push_front(key);
            hashmap[key] = {keyList.begin(), value};
            capacity--;
        }
        else
        {
            hashmap[key].second = value;
            moveKeyToFront(key);
        }

        // 移除 lru cache
        if (capacity < 0)
        {
            hashmap.erase(keyList.back());
            keyList.pop_back();
            capacity++;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */