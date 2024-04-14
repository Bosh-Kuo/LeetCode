/**
time complexity: O(n)
tags: Math, String, Stack
note: 將字串中的數字處理成待加總的數字陣列，最後再將這些數字加總
1. 當遇到運算符時，根據先前遇到的運算符類型決定如何操作暫存起來的數字
2. 操作乘除法時，先將容器中最新的數字提出，運算完後再放回容器
*/

class Solution
{
public:
    int calculate(string s)
    {
        vector<int> numStack;
        long curr = 0;
        char op = '+';

        for (int i = 0; i < s.size(); i++)
        {
            // 將字串轉整數，並暫存起來
            if (isdigit(s[i]))
                curr = curr * 10 + s[i] - '0';

            // 遇到 operator 或最後一個 char，先處裡之前暫存於的 op 的 operator
            // ex: 1 + 13 / 5 => 當 s[i] == '/', op 為 '+', curr 為 13，先處理 + 與 13
            if (i == s.size() - 1 || s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/')
            {
                if (op == '+')
                    numStack.push_back(curr);
                else if (op == '-')
                    numStack.push_back(-curr);
                else
                {
                    // 遇到 * or / 時，先把 numStack 中最新存入的數 pop 出來運算，再存入
                    int num = numStack.back();
                    numStack.pop_back();
                    if (op == '*')
                        numStack.push_back(num * curr);
                    else
                        numStack.push_back(num / curr);
                }
                curr = 0;
                op = s[i];
            }
        }
        return accumulate(numStack.begin(), numStack.end(), 0);
    }
};