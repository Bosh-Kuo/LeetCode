/*
time complexity: O(log(dividend/divisor))
tags: Math, Bit Manipulation
note: ex: 53 / 3:
53 - 3*(1*2*2*2*2) = 5 > 3
5 - 3*(1) = 2 < 3
ans = (1*2*2*2*2) + 1 =17
*/
class Solution
{
public:
    int divide(int dividend, int divisor)
    {
        // 因 INT_MIN = -2147483648，若直接計算會得到 2^31，超出了 32-bit int 的範圍所以直接回傳 2^31 - 1
        if (dividend == INT_MIN && divisor == -1)
        {
            return INT_MAX;
        }

        if (divisor == 1)
            return dividend;

        long long absDividend = labs(dividend), absDivisor = labs(divisor);
        long long ans = 0;
        int sign = (dividend > 0 ^ divisor > 0) == 0 ? 1 : -1;

        while (absDividend >= absDivisor)
        {
            long long temp = absDivisor;
            int mul = 1;
            while (temp << 1 <= absDividend)
            {
                temp <<= 1;
                mul << 1;
            }
            absDividend -= absDivisor * mul;
            ans += mul;
        }
        return sign * ans;
    }
};
