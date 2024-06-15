/*
time complexity: O(1)
tags: Math
note: 把所有位數都存起來再逐一比對
*/
class Solution
{
public:
    bool isPalindrome(int x)
    {
        if (x < 0)
            return false;
        else if (x == 0)
            return true;
        else
        {
            vector<int> digits;
            while (x > 0)
            {
                digits.push_back(x % 10);
                x = x / 10;
            }
            for (int i = 0; i < digits.size(); i++)
            {
                if (digits[i] != digits[digits.size() - 1 - i])
                    return false;
            }
            return true;
        }
    }
};