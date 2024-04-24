/*
time complexity:
tags: String, Stack, Recursion
note: 用 stack 暫存走訪過的每個 char，當遇到 ] 就把 stack 遇到第一個 [ 之前的 char pop 出來解碼，
再將解碼完的字串 push 回去，最終 stack 內的 char 就是最終答案的組成
ex: 3[a2[c]] -> 3[acc] -> accaccacc
*/

class Solution
{
public:
    string decodeString(string s)
    {
        stack<char> stringStack;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] != ']')
            {
                stringStack.push(s[i]);
            }
            else
            {
                string curr_str = "";
                string number = "";

                // 遇到 ']' 時，從 stack 中 pop 回 [] 內的字串
                while (stringStack.top() != '[')
                {
                    curr_str = stringStack.top() + curr_str;
                    stringStack.pop();
                }
                stringStack.pop(); // for '['

                // [ 的前面一定接一個 number
                while (!stringStack.empty() && isdigit(stringStack.top()))
                {
                    number = stringStack.top() + number;
                    stringStack.pop();
                }
                int k_time = stoi(number); // convert string to number

                // 把 k[encoded_string] 解碼後在 push 回 stack
                while (k_time--)
                {
                    for (int p = 0; p < curr_str.size(); p++)
                        stringStack.push(curr_str[p]);
                }
            }
        }

        s = "";
        while (!stringStack.empty())
        {
            s = stringStack.top() + s;
            stringStack.pop();
        }
        return s;
    }
};