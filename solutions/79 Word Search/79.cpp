/*
time complexity:
tags: Array, Backtracking, Matrix
note: 此題必須用 backtracking 來搜索，且需要用 for loop 嘗試以每個 element 作為搜索起點。
先思考搜索的終止條件：1. 搜索位置超出邊界 -> 回傳 false, 2. 與目前要找的字母不同 -> 回傳 false
3. 與目前找的 character 相同且為最後一個要找的字母，回傳 -> true
往下搜索之前要先記錄目前已經搜索過的位置，可以直接更改 board 來做記號。若在該位置上往下搜索的每條路徑都失敗，表示必須從目前這個位置回到上個位置，必須將在 board 上的鏢擊移除
*/

class Solution
{
public:
    bool backtracking(vector<vector<char>> &board, string &word, int order, int x, int y)
    {
        // 終止條件：
        // 1. x, y 違法 -> 回傳 false
        // 2. 該 node 與目前找的 character 不同 -> 回傳 false，
        // 3. 該 node 與目前找的 character 相同且為最後一個要找的 character 回傳 -> true

        if (x < 0 || x >= board.size() || y < 0 || y >= board[0].size())
            return false;
        if (board[x][y] != word[order])
            return false;
        if (board[x][y] == word[order] && order == word.size() - 1)
            return true;

        // 若未達終止條件，表示目前位置符合要找的 character，必須在 board 上標記該位置已走過
        board[x][y] = '@';

        // 依照上、右、下、左的順序往下搜尋
        bool isSuccess = backtracking(board, word, order + 1, x - 1, y) || backtracking(board, word, order + 1, x, y + 1) ||
                         backtracking(board, word, order + 1, x + 1, y) || backtracking(board, word, order + 1, x, y - 1);

        // 把 board 上的標記還原
        board[x][y] = word[order];
        return isSuccess;
    }
    bool exist(vector<vector<char>> &board, string word)
    {
        // 要有一個 for loop 輪流讓每個 element 當開頭

        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[0].size(); j++)
            {
                bool isSuccess = backtracking(board, word, 0, i, j);
                if (isSuccess)
                    return true;
            }
        }
        return false;
    }
};