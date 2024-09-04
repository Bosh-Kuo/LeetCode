/*
time complexity : O(n)
tags: String
note: 使用 stringstream 串接 count, digit
*/

class Solution
{
public:
    string countAndSay(int n)
    {
        string ans = "1";
        for (int i = 1; i < n; i++)
        {
            ans = countAndMerge(ans);
        }
        return ans;
    }

private:
    string countAndMerge(const string &s)
    {
        int len = s.length();
        stringstream ss;
        int count = 1;

        for (int i = 1; i < len; i++)
        {
            if (s[i] == s[i - 1])
            {
                count++;
            }
            else
            {
                ss << count << s[i - 1];
                count = 1;
            }
        }
        ss << count << s[len - 1];

        return ss.str();
    }
};
