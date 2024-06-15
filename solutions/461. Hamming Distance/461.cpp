/*
time complexity: O(n)
tags: Bit Manipulation
note: 使用 XOR 將 x, y 所有不相同的位元轉成 1，相同的位元轉成 0，在統計有多少個位元為 1
*/

class Solution
{
public:
    int hammingDistance(int x, int y)
    {
        int xXORy = x ^ y;
        int count = 0;
        // 但是每次都刪掉 xor 的最右位元。
        for (; xXORy; xXORy >>= 1)
            if (xXORy & 1)
                count += 1;
        return count;
    }
};