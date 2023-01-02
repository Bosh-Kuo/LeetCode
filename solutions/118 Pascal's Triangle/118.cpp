/*
time complexity: O(n^2)
tags: Array, Dynamic Programming
note: 判斷每個 row 有幾個元素。開頭或結尾直接加入 array，其餘的則等於上一個 row 的 index i-1, i 的和
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<vector<int>> generate(int numRows)
    {
        vector<vector<int>> Ans;
        for (int row = 0; row < numRows; row++)
        {
            int i = 0, numOfElement = row + 1;
            vector<int> temp;
            while (i < numOfElement)
            {
                if (i == 0 || i == numOfElement - 1)
                    temp.push_back(1);
                else
                {
                    temp.push_back(Ans[row - 1][i - 1] + Ans[row - 1][i]);
                }
                i++;
            }
            Ans.push_back(temp);
        }
        return Ans;
    }
    
};