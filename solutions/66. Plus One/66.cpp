/*
time complexity: O(n)
tags: Array, Math
note: 從最後一位開始進行加法，如果該位數加完後需要進位就把下一個位數加一，重複執行到最大位數，若最大位數需要進位就在 vector.begin() insert 1
*/

class Solution
{
public:
    vector<int> plusOne(vector<int> &digits)
    {
        int carry = 0;
        for (int i = digits.size() - 1; i >= 0; i--)
        {
            if (i == digits.size() - 1)
            {
                carry = (digits[i] + 1) / 10;
                digits[i] = (digits[i] + 1) % 10;
            }
            else
            {
                int temp = carry;
                carry = (digits[i] + temp) / 10;
                digits[i] = (digits[i] + temp) % 10;
            }
            if (i == 0 && carry == 1)
                digits.insert(digits.begin(), 1);
        }
        return digits;
    }
};