/*
time complexity: O(m*n)
tags: Array, Matrix, Simulation
note: 需要折返的輪數 = row + col - 1，先確認每一輪出發的起始位置，並判斷這輪要往右上還是左下走，若走出界則結束這一輪
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> findDiagonalOrder(vector<vector<int>> &mat)
    {
        vector<int> Ans;
        // 共要折返幾輪
        int round = mat.size() + mat[0].size() - 1;
        int rows = mat.size(), cols = mat[0].size();

        for (int i = 0; i <= round; i++)
        {
            bool leftToRight = (i % 2 == 0);

            // 決定該 round 的起始位置
            int row, col;
            if (leftToRight)
            {
                row = (i >= rows) ? (rows - 1) : i;
                col = i - row;
            }
            else
            {
                col = (i >= cols) ? (cols - 1) : i;
                row = i - col;
            }
            while ((row >= 0 && row < rows) && (col >= 0 && col < cols))
            {
                Ans.push_back(mat[row][col]);
                if (leftToRight)
                {
                    row--;
                    col++;
                }
                else
                {
                    row++;
                    col--;
                }
            }
        }
        return Ans;
    }
};

int main()
{
    vector<vector<int>> mat = {{1,2,3}, {4,5,6}, {7,8,9}};
    vector<int> Ans;
    Solution sol;
    Ans = sol.findDiagonalOrder(mat);
    for (auto e: Ans)
        cout << e << " ";
}