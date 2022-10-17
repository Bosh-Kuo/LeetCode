/*
time complexity: O(n)
tags: Array, Dynamic Programming
note: Pascal triangle 速解法：第 n row 為 C_n_0, C_n_1, ... C_n_n
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> getRow(int rowIndex)
    {
        vector<int> ans = {1};
        long long numerator = rowIndex, denominator = 1;
        long long C_n_i = numerator / denominator;
        for (int i = 1; i <= rowIndex; i++)
        {
            ans.push_back(C_n_i);
            numerator -= 1;
            denominator += 1;
            C_n_i = C_n_i * numerator / denominator;
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    vector<int> ans = sol.getRow(0);
    for (int i : ans)
        cout << i << " ";
}