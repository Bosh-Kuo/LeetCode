/*
time complexity: 
tags: Array, Binary Search, Divide and Conquer, Matrix
note: 這題用 Divide and Conquer 來解，想法是當目標比當前的位置小代表當前位置的右下角都可以排除，
當目標比當前的位置大代表當前位置的左上角都可以排除，將問題分解成許多小區塊，當目標有在其中一個小區塊則回傳 true
*/


#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    bool recursive_helper(vector<vector<int>> &matrix, int left, int right, int top, int bottom, int target)
    {
        // base case
        if (left > right || top > bottom)
            return false;

        // find pivot
        int col_pivot = (left + right) / 2;
        int row_pivot = (top + bottom) / 2;

        // check pivot
        if (matrix[row_pivot][col_pivot] == target)
            return true;

        // delete top_left(左上)
        if (matrix[row_pivot][col_pivot] < target)
        {
            bool top_right = recursive_helper(matrix, col_pivot + 1, right, top, row_pivot, target);
            bool bottom_left_right = recursive_helper(matrix, left, right, row_pivot + 1, bottom, target);
            return (top_right || bottom_left_right);
        }

        // delete bottom_right(右下)
        if (matrix[row_pivot][col_pivot] > target)
        {
            bool bottom_left = recursive_helper(matrix, left, col_pivot - 1, row_pivot, bottom, target);
            bool top_left_right = recursive_helper(matrix, left, right, top, row_pivot - 1, target);
            return (bottom_left || top_left_right);
        }
    }
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int left = 0, top = 0;
        int right = matrix[0].size() - 1, bottom = matrix.size() - 1;
        return recursive_helper(matrix, left, right, top, bottom, target);
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> test{{1, 4, 7, 11, 15},
                             {2, 5, 8, 12, 19},
                             {3, 6, 9, 15, 22},
                             {4, 7, 10, 16, 23},
                             {10, 13, 14, 17, 24},
                             {18, 21, 23, 26, 30}};
    cout << sol.searchMatrix(test, 31);
}
