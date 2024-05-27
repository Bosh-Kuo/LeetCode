/*
time complexity: O(n)
tags: Two Pointers, String, Stack, Simulation
note:
*/

class Solution
{
public:
    string covert(string s)
    {
        stack<char> st;
        for (char &c : s)
        {
            if (c == '#')
            {
                if (st.empty())
                    continue;
                else
                    st.pop();
            }
            else
            {
                st.push(c);
            }
        }
        string covertS = "";
        while (!st.empty())
        {
            covertS += st.top();
            st.pop();
        }
        return covertS;
    }
    bool backspaceCompare(string s, string t)
    {
        string covertS = covert(s);
        string covertT = covert(t);
        return covertS == covertT;
    }
};