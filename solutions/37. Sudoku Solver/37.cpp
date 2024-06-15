/*
time complexity: 
tags: Array, Backtracking, Matrix
note: 依序迭代所有空格，在空格內嘗試填入 1 ~ 9，若不違反規則，則往下一格移動。當某一格無發田入任和數字，代表前面的格子有問題，必須把當前的格子清空，
回到上一格填入其他數字。當前前進到最後一個格子都沒有遇到不符合規則的狀況，表示當前的 board 就是解答，即可停止迭代。
*/

#include <iostream>
#include <vector>
using namespace std;

void printBoard(vector<vector<char>> &board)
{
    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[i].size(); j++)
            cout << board[i][j] << ' ';
        cout << endl;
    }
}

class Solution
{
public:
    bool is_valid(vector<vector<char>> &board, int position, char number)
    {
        int row = position / 9, col = position % 9;

        // 同 row 上不可重複
        for (int i = 0; i < 9; i++)
        {
            if (board[row][i] == number)
                return false;
        }

        // 同 col 上不可重複
        for (int i = 0; i < 9; i++)
        {
            if (board[i][col] == number)
                return false;
        }

        // 同個 block 內不可重複
        int row_low = (row / 3) * 3, row_high = (row / 3) * 3 + 2;
        int col_low = (col / 3) * 3, col_high = (col / 3) * 3 + 2;
        for (int i = row_low; i <= row_high; i++)
        {
            for (int j = col_low; j <= col_high; j++)
            {
                if (board[i][j] == number)
                    return false;
            }
        }

        return true;
    }
    bool backtrack(vector<vector<char>> &board, int position)
    {
        // 所有格子都填完了
        if (position == 9 * 9)
            return true;

        int row = position / 9, col = position % 9;

        // 若該格子是題目預填的，直接往下一格走
        if (board[row][col] != '.')
            return backtrack(board, position + 1);
        else
        {
            // 把這格所有的數字掃過一輪
            for (char number = '1'; number <= '9'; number++)
            {
                if (is_valid(board, position, number))
                {
                    // 填入數字
                    board[row][col] = number;

                    // 往下一格繼續走
                    bool finish = backtrack(board, position + 1);

                    // 完成 sudoku 就中止迭代
                    if (finish)
                        return true;

                    // backtracking: 後面的格子都掃過一遍後，當前格子填入下一個數字
                    board[row][col] = '.';
                }
            }
            return false;
        }
    }

    void solveSudoku(vector<vector<char>> &board)
    {
        bool state = backtrack(board, 0);
    }
};

int main()
{
    vector<vector<char>> board =
        {{'5', '3', '.', '.', '7', '.', '.', '.', '.'},
         {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
         {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
         {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
         {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
         {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
         {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
         {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
         {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};
    Solution sol;
    sol.solveSudoku(board);
    printBoard(board);
}