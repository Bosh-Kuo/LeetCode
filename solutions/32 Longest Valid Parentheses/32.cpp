/*
time complexity: O(n)
tags: String, Dynamic Programming, Stack
note:
當遇到 '('時，把該 index 加入 stack，
當遇到 ')'且 stack 不為空時，把 s[stack.top()] 與 s[i] 標記起來，因為一個 ')' 必會與一個'(' 組成一組 parentheses。
最後再找出最長的連續標記長度
*/

class Solution
{
public:
    int longestValidParentheses(string s)
    {
        int maxLength = 0;
        int length = 0;

        stack<int> myStack;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '(')
                myStack.push(i);
            else if (!myStack.empty())
            {
                s[myStack.top()] = '*';
                s[i] = '*';
                myStack.pop();
            }
        }
        for (int i = 0; i <= s.size(); i++)
        {
            if (s[i] == '*')
                length++;
            else
            {
                maxLength = max(length, maxLength);
                length = 0;
            }
        }
        return maxLength;
    }
};