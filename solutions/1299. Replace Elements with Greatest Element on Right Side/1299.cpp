/*
time complexity : O(n)
tags: Array
note: 從尾走回頭，若遇到最後一個元素，存下路上遇到的最大值，直接改為 -1，其他元素則改為存下的最大值
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        // 從尾走回頭
        int max = arr[arr.size() - 1];
        for (int i = arr.size() - 1; i >= 0; i --)
        {
            if (i == arr.size() - 1)
                arr[i] = -1;
            else
            {
                int temp = arr[i];
                arr[i] = max;
                max = (max > temp) ? max : temp;
            }
        }
        return arr;
    }
};