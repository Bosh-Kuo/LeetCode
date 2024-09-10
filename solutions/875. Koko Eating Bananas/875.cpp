/*
time complexity : O(n*log(m)), n means length of piles, m means Max(piles[i])
tags: Array, Binary Search
note: 直接用 Binary Search 硬找
*/

class Solution
{
public:
    bool canFinish(vector<int> &piles, int h, int eat)
    {
        int hour = 0;
        for (int i = 0; i < piles.size(); i++)
        {
            hour += piles[i] / eat;
            if (piles[i] % eat != 0)
                hour += 1;
            if (hour > h)
                return false;
        }
        return hour <= h;
    }

    int minEatingSpeed(vector<int> &piles, int h)
    {
        int low = 1;
        int high = *max_element(piles.begin(), piles.end());

        while (low < high)
        {
            int mid = (low + high) / 2;
            if (canFinish(piles, h, mid))
                high = mid;
            else
                low = mid + 1;
        }
        return low;
    }
};
