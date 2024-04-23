/*
time complexity: O(1)
tags: Array, Hash Table, Math, Design, Randomized
note: getRandom 使用 std:advance 將迭代器移動到隨機步數以後
*/

class RandomizedSet
{
private:
    unordered_set<int> hashset;

public:
    RandomizedSet()
    {
    }

    bool insert(int val)
    {
        if (hashset.count(val) == 0)
        {
            hashset.insert(val);
            return true;
        }
        else
            return false;
    }

    bool remove(int val)
    {
        if (hashset.count(val) != 0)
        {
            hashset.erase(val);
            return true;
        }
        else
            return false;
    }

    int getRandom()
    {
        auto it = hashset.begin();
        int n = rand() % hashset.size();
        advance(it, n);
        return *it;
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */