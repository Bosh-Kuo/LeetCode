/*
time complexity : O(n)
tags: Array
note: 當 arr 長度小於 3 或只有上升或下降的話就回傳 false，在遍歷過程中依照目前是上升中還是下降中來檢查元素前後之間的大小關係
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    bool validMountainArray(vector<int> &arr)
    {
        // base case
        if (arr.size() < 3)
            return false;

        if (arr[1] <= arr[0])
            return false;

        // 一開始必須是上升狀態
        bool climbing = true;
        for (int i = 1; i < arr.size(); i++)
        {
            if (climbing)
            {
                if (arr[i] < arr[i - 1])
                    climbing = false;
                else if (arr[i] == arr[i - 1])
                    return false;
            }
            else
            {
                if (arr[i] >= arr[i - 1])
                    return false;
            }
        }

        // 結束必須在下降狀態
        if (climbing)
            return false;
        else
            return true;
    }
};

int main()
{
    Solution sol;
    vector<int> arr = {3, 5, 3};
    cout << sol.validMountainArray(arr);
}