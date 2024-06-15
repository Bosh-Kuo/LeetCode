/*
time complexity: 
tags: Array, Backtracking
note: 迭代每一層 row 決定在該層 row 要把 Q 放置在什麼位置。當前的 row 上某個 col 可以安全放置 Q ，就往下一層 row 繼續走，
當前的 row 以下的 row 都完整迭代過一遍後，就把當前 row 上的 Q 拿起，往後放一格繼續迭代。當所在的 row 已經是最後一層 row ，且當前的 col 位置可以安全放置 Q
，就代表一組解產生了。
reference: 
https://www.techiedelight.com/zh-tw/print-possible-solutions-n-queens-problem/
https://cloud.tencent.com/developer/article/1424758
*/

#include <iostream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

class Solution
{
public:
    void addOneAns(vector<int> &colIndex, vector<vector<string>> &Ans)
    {
        int N = colIndex.size();
        vector<string> oneAns = {};

        for (int i = 0; i < N; i++)
        {
            string oneRow = "";
            for (int j = 0; j < N; j++)
            {
                if (colIndex[i] == j)
                    oneRow.append("Q");
                else
                    oneRow.append(".");
            }
            oneAns.push_back(oneRow);
        }
        Ans.push_back(oneAns);
    }
    void printAllAns(vector<vector<string>> &Ans)
    {
        int numOfAns = Ans.size();
        for (int i = 0; i < numOfAns; i++)
        {
            for (int j = 0; j < Ans[i].size(); j++)
                cout << Ans[i][j] << endl;

            cout << endl;
        }
    }
    bool isSafe(int row, int col, vector<int> &colIndex)
    {
        // 有兩 Q 在同一個 col 上
        for (int i = 0; i < colIndex.size(); i++)
        {
            if (col == colIndex[i])
                return false;
        }
        // 有兩 Q 在同一對角線上
        for (int i = 0; i < colIndex.size(); i++)
        {
            if (abs(row - i) == abs(col - colIndex[i]))
                return false;
        }
        return true;
    }
    void backtrack_nqueen(vector<vector<string>> &Ans, vector<int> &colIndex, int row, int n)
    {
        // 如果已經到最底的 row 了，並且放置成功，就把答案加到 Ans 裡面
        if (row == n)
        {
            addOneAns(colIndex, Ans);
            return;
        }

        // 掃過這個 row，看這個 row 上哪個 col 可以放置 Q
        for (int col = 0; col < n; col++)
        {
            if (isSafe(row, col, colIndex))
            {
                // 在這個位置放下 Q，
                colIndex.push_back(col);

                // 往下一個 row 繼續走
                backtrack_nqueen(Ans, colIndex, row + 1, n);

                // backtracking：如果往下的 row 都跑完了，就把 Q 拿起，接著繼續往下放
                colIndex.pop_back();
            }
        }
    }

    vector<vector<string>> solveNQueens(int n)
    {
        vector<vector<string>> Ans; 
        vector<int> colIndex; // 每個 row 上 Q 所在的 col index
        backtrack_nqueen(Ans, colIndex, 0, n);
        return Ans;
    }
};

int main()
{
    
    Solution sol;
    vector<vector<string>> Ans = sol.solveNQueens(4);
    sol.printAllAns(Ans);
}