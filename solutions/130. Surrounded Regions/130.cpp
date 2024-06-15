/*
time complexity: O(m*n)
tags: Array, Depth-First Search, Breath-First Search, Union Find, Matrix
note: 本題用 DFS 來解。
先以 DFS 將與邊緣相連的 'O' 轉成 '1'，最後再把剩餘的 'O' 轉為 'X'
*/

class Solution
{
public:
    void solve(vector<vector<char>> &board)
    {
        if (board.empty())
            return;
        int row = board.size(), col = board[0].size();
        for (int i = 0; i < row; ++i)
        {
            check(board, i, 0);       // first column
            check(board, i, col - 1); // last column
        }
        for (int j = 1; j < col - 1; ++j)
        {
            check(board, 0, j);       // first row
            check(board, row - 1, j); // last row
        }
        for (int i = 0; i < row; ++i)
            for (int j = 0; j < col; ++j)
                if (board[i][j] == 'O')
                    board[i][j] = 'X';
                else if (board[i][j] == '1')
                    board[i][j] = 'O';
    }

    void check(vector<vector<char>> &board, int i, int j)
    {
        if (board[i][j] == 'O')
        {
            board[i][j] = '1';
            if (i > 1)
                check(board, i - 1, j);
            if (j > 1)
                check(board, i, j - 1);
            if (i + 1 < board.size())
                check(board, i + 1, j);
            if (j + 1 < board[0].size())
                check(board, i, j + 1);
        }
    }
};