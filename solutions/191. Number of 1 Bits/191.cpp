/*
time complexity: O(1)
tags: Divide and Conquer, Bit Manipulation
note: 1 表示所有位數為 0，最右邊的位數為1，若要計算 n 總共有幾個 1 可以用 n & 1 得知 n 最右邊的位數是否為 0，
再將 n 向右移一個 bit，直到所有 bit 都與 1 計算過
*/
class Solution
{
public:
    int hammingWeight(uint32_t n)
    {
        int answer = 0;
        for (int i = 0; i < 32; i++)
        {
            // 只看最右邊的位數
            answer += n & 1;
            // 將 n 右移一個 bit
            n >>= 1;
        }
        return answer;
    }
};