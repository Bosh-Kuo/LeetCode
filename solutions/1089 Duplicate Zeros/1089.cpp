/*
time complexity : O(n)
tags: Array, Two Pointers
note: 當第 i 個元素為 0 時，在他前面插入 0，並且 i 向後走一步，再 pop 掉最後一個元素
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    void duplicateZeros(vector<int> &arr)
    {
        for (int i = 0; i < arr.size(); i++)
        {
            if (arr[i] == 0)
            {
                arr.insert(arr.begin() + i, 0);
                arr.pop_back();
                i++;
            }
        }
    }
};