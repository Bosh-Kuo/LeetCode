/*
time complexity: O(log(n))
tags: Math, Bit Manipulation
note: 先用 XOR 算出不需要進位的位數的加法結果，再用 AND 算出需要進位數字。重複拿前兩者做 XOR 直到不再有進位為止
*/

class Solution
{
public:
    int getSum(int a, int b)
    {
        int sum = a;
        // ex: 01101 + 00011 = 01110 + 00010 = 01100 + 00100 = 01000 + 01000 = 00000 + 10000 = 10000
        while (b != 0)
        {
            sum = a ^ b;      // XOR (不考慮進位)
            b = (a & b) << 1; // 進位
            a = sum;
        }
        return sum;
    }
};