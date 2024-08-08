/*
time complexity: O(log(N))
tags: Hash Table, Math, Two Pointers
note: 用 set 儲存出現過的數字判斷是否進入 cycle
*/

class Solution
{
public:
    bool isHappy(int n)
    {
        unordered_set<int> uset;
        while (n != 1)
        {
            int temp = n;
            n = 0;
            while (temp > 0)
            {
                n += (temp % 10) * (temp % 10);
                temp /= 10;
            }
            if (uset.count(n) > 0)
                return false;
            uset.insert(n);
        }
        return true;
    }
};