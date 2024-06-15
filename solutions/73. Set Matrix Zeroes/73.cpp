/*
time complexity : O(mn)
tags: Array, Hash Table, Matrix
note: 找出要填 0 的 row, col，將這些 row, col 上的元素填 0
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int rows = matrix.size(), cols = matrix[0].size();
        vector<int>row(rows);
        vector<int>col(cols);
        // 找出要填 0 的 row, col
        for (int i = 0; i < rows; i++)
        {
            for(int j = 0; j < cols; j++)
            {
                if (matrix[i][j] == 0)
                {
                    row[i] ++;
                    col[j] ++;
                }                    
            }
        }
        // 將這些 row, col 填 0
        for (int i = 0; i < rows; i++)
        {
            for(int j = 0; j < cols; j++)
            {
                if (row[i] != 0 || col[j] != 0)
                {
                    matrix[i][j] = 0;
                } 
            }
        }
        
    }
};