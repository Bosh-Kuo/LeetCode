/*
time complexity: O(n)
tags: Array, Math, Enumeration, Number Theory
note: 用 hashTable 紀錄是否為質數。
*/

class Solution
{
public:
    int countPrimes(int n)
    {
        vector<int> hashTable(n + 1);
        int count = 0;
        for (int i = 2; i * i < n; i++) // 大於 sqrt(n) 的非質數必定為小於 sqrt(n) 的質數的倍數
        {
            if (hashTable[i] == 0)
            {
                for (int j = i * i; j < n; j += i)
                    hashTable[j] = 1;
            }
        }
        for (int i = 2; i < n; i++)
        {
            if (hashTable[i] == 0)
                count++;
        }
        return count;
    }
};