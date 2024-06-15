/*
time complexity: O(n)
tags: Array, Greedy
note:
1. 若 cost 總體大於 gas 回傳 -1
2. 若 gas[i] - cost[i] 從 i = 0 開始累加，累加值恆大於 0 則回傳 0
3. 若累加值曾小於 0，則回傳累加值最小值發生的 index + 1
*/

class Solution
{
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
    {
        // 1. 若 cost 總體大於 gas 回傳 -1
        // 2. 若 gas[i] - cost[i] 從 i = 0 開始累加，累加值恆大於 0 則回傳 0
        // 3. 若累加值曾小於 0，則回傳累加值最小值發生的 index + 1
        int rest = 0, minRest = INT_MAX, minIdx = 0;
        for (int i = 0; i < gas.size(); i++)
        {
            rest += gas[i] - cost[i];
            if (rest < minRest)
            {
                minIdx = i;
                minRest = rest;
            }
        }

        if (rest < 0)
            return -1;
        if (minRest >= 0)
            return 0;
        else
            return minIdx + 1;
    }
};