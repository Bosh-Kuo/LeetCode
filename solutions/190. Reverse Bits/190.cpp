/*
time complexity: O(1)
tags: Divide and Conquer, Bit Manipulation
note: 直接從調整整數的位元的角度來切入，就不用先將位元轉為字串，再反轉，再轉回整數。
*/
class Solution
{
public:
    uint32_t reverseBits(uint32_t n)
    {
        uint32_t ans = 0; // 初始化答案為 0
        for (int i = 0; i < 32; i++)
        {                   // 對於 n 的每一位元
            ans <<= 1;      // 將 ans 向左移動一位，為新位元腾出空間
            ans |= (n & 1); // 取出 n 的最低位元並將其加到 ans 的最低位
            n >>= 1;        // 將 n 向右移動一位，準備處理下一位
        }
        return ans; // 返回反轉後的結果
    }
};