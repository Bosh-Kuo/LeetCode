/**
time complexity: O(n)
tags: Math, String, Stack, Recursion
note: 由於 "-" 同時代表"負"又代表"減法"運算符，為統一處理方式，一律視為「前數加上負的 ...」，若沒有前數，則令前數為 0
// ex: "-(-(4+5+2)-3)+(-6+8)" 視為 "0-(0-(4+5+2)-3)+(0-6+8)"
1. 若完全沒有 "()" => 從頭一路累加到尾
2. 遇到 "("，將 "(" 前的加總暫存起來(numStack.push)，並把  "(" 前的運算子存起來(opStack.push)，並從頭開始累加 () 內的加總
3. 遇到 ")"，將 "()" 內的加總乘上 "(" 前的運算子(opStack.top)，再加上 "(" 前的加總(numStack.top)。
4. 若最後一個字元不是 ")"，必須把最後一個計算的數值也累加進去
*/
Ｆ

    class Solution
{
public:
    int calculate(string s)
    {
        stack<int> numStack, opStack;
        int curr = 0, sign = 1;
        long temp = 0;
        for (char c : s)
        {
            if (isdigit(c))
                temp = temp * 10 + (c - '0');
            else
            {
                curr = curr + sign * temp;
                temp = 0;
                if (c == '+')
                    sign = 1;
                else if (c == '-')
                    sign = -1;
                else if (c == '(')
                {
                    numStack.push(curr);
                    opStack.push(sign);
                    curr = 0;
                    sign = 1;
                }
                // 遇到 )，把在 ( 以後的加總乘上 ( 前的運算元，再加上遇到 ( 前的加總
                else if (c == ')' && opStack.size())
                {
                    curr = curr * opStack.top() + numStack.top();
                    opStack.pop();
                    numStack.pop();
                }
            }
        }

        curr += sign * temp;
        return curr;
    }
};