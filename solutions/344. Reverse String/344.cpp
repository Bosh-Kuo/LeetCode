/*
time complexity: O(n)
tags: Two Pointers, String
note: 以左右兩端為起點一邊互換一邊向中間走，最多走 n/2 步可完成
*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


class Solution
{
public:
    void reverseString(vector<char> &s)
    {
        int left = 0, right = s.size() - 1;
        recursive_swap(s, left, right);
    }
    void recursive_swap(vector<char> &s, int left, int right)
    {
        if (left >= right)
            return;
        swap(s[left], s[right]);
        recursive_swap(s, left+1, right-1);
    }
};

int main()
{
    Solution sol;
    vector<char> test_case = {'h', 'e', 'l', 'l', 'o'};
    sol.reverseString(test_case);
    for (char i : test_case)
    {
        cout << i << " " << endl;
    }
    return 0;
}