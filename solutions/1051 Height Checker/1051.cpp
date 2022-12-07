/*
time complexity: O(nlog(n))
tags: Array, Sorting, Counting Sort
note: 先排好再一個一個比
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> expected = heights;
        sort(expected.begin(), expected.end());
            int count = 0;
            for(int i = 0; i < expected.size(); i++)
                if(expected[i] != heights[i])
                    count++;
        return count;
    }
};
