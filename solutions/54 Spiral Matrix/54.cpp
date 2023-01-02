/*
time complexity: O(m*n)
tags: Array, Matrix, Simulation
note: 依照右下左上的順序前進，並且設定4個方向的邊界，當在某個方向走到底後，邊界就向內縮1單位直，直到無法繼續往下走停止。
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution
{ 
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        vector<int> Ans;
        int m = matrix.size(), n = matrix[0].size();
        int left = 0, right = n - 1, top = 0, bottom = m - 1;
        int x = 0, y = 0;
        char direction = 'r';

        while (x >= left && x <= right && y >= top && y <= bottom)
        {
            Ans.push_back(matrix[y][x]);
            switch (direction)
            {
            case 'r':
                if (x == right)
                {
                    direction = 'd';
                    y += 1;
                    top += 1;
                }
                else
                    x += 1;
                break;
            case 'l':
                if (x == left)
                {
                    direction = 'u';
                    y -= 1;
                    bottom -= 1;
                }
                else
                    x -= 1;
                break;
            case 'u':
                if (y == top)
                {
                    direction = 'r';
                    x += 1;
                    left += 1;
                }
                else
                    y -= 1;
                break;
            default:
                if (y == bottom)
                {
                    direction = 'l';
                    x -= 1;
                    right -= 1;
                }
                else
                    y += 1;
                break;
            }
        }
        return Ans;
    }
};
int main()
{
    vector<vector<int>> matrix = {{1,2,3},{4,5,6},{7,8,9}};
    Solution sol;
    vector<int> Ans = sol.spiralOrder(matrix);
    for (auto e: Ans)
        cout << e << " ";
}