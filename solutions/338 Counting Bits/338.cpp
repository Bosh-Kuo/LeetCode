/*
time complexity: O(n)
tags: Dynamic Programming, Bit Manipulation
note: from 0~15: [0, 1], [10, 11], [100, 101, 110, 111], [1000, 1001, 1010, 1011, 1100, 1101, 1110, 1111]...
number of 1's in the binary representation of i = array[i >> 1] + i%2
*/

class Solution
{
public:
    vector<int> countBits(int n)
    {
        vector<int> answer = {0};
        for (int i = 1; i <= n; i++)
        {
            int numOfOne = answer[i >> 1] + i % 2;
            answer.push_back(numOfOne);
        }

        return answer;
    }
};