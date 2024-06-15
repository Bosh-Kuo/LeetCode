/**
time complexity: O(n)
tags: String
note: 建立長度為 numRows 的 string vector，逐字元移動 index，碰到邊緣轉換方向
*/

class Solution
{
public:
    string convert(string s, int numRows)
    {
        if (numRows == 1)
        {
            return s;
        }

        string ans = "";
        vector<string> rows(numRows, "");
        bool positiveDir = false;
        int currentRow = 0;

        for (int i = 0; i < s.length(); i++)
        {
            if (currentRow == 0 || currentRow == numRows - 1)
                positiveDir = !positiveDir;

            rows[currentRow] += s[i];
            if (positiveDir)
                currentRow += 1;
            else
                currentRow -= 1;
        }

        for (auto row : rows)
            ans += row;

        return ans;
    }
};