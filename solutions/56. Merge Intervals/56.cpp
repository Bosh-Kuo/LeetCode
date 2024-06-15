/*
time complexity: O(nlog(n))
tags: Array, Sorting
note: 先將 2D array 每一 row 的第一個 element 排序好。逐個比較 tail 與後一個 interval 的 head 與 tail 的關係。
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        // sort: 依照每個 row 第一個 element 來排序 
        sort(intervals.begin(), intervals.end()); 

        int head = intervals[0][0];
        int tail = intervals[0][1];
        for (int i = 1; i < intervals.size(); i++)
        {
            if (tail < intervals[i][0])
            {
                ans.push_back({head, tail});
                head = intervals[i][0];
                tail = intervals[i][1];
            }
            else if (tail <= intervals[i][1])
            {
                tail = intervals[i][1];
            }
        }
        ans.push_back({head, tail});
        return ans;
    }
};

int main()
{
    vector<vector<int>> two_D_vector{
        {3, 5, 4},
        {6, 4, 2},
        {1, 7, 3}};

    sort(two_D_vector.begin(), two_D_vector.end());
    for (int i = 0; i < two_D_vector.size(); i++)
    {
        for (int j = 0; j < two_D_vector[0].size(); j++)
        {
            cout << two_D_vector[i][j] << " ";
        }
        cout << endl;
    }


        
}