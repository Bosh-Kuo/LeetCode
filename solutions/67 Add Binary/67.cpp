/*
time complexity: O(n)
tags: Math, String, Bit Manipulation, Simulation
note: 先確認要處理的最大長度，若其中一個 string 長度小於該最大長度則處理時以 0 代替。
從兩個 string 各自的最小位數開始處理，在一個 digit 上的相加結果只會有4種可能的情況。
*/

#include <iostream>
#include <string>
using namespace std;

class Solution
{
public:
    string addBinary(string a, string b)
    {
        int maxLength = a.length() >= b.length() ? a.length() : b.length();
        int carry = 0;
        string Ans = "";
        for (int i = 0; i < maxLength; i++)
        {
            int digit_a = a.length() <= i ? 0 : a[a.length()-1-i]-'0';
            int digit_b = b.length() <= i ? 0 : b[b.length()-1-i]-'0';
            switch (digit_a + digit_b + carry){
                case 0:
                    Ans.push_back('0');
                    carry = 0;
                    break;
                case 1:
                    Ans.push_back('1');
                    carry = 0;
                    break;
                case 2:
                    Ans.push_back('0');
                    carry = 1;
                    break;
                default:
                    Ans.push_back('1');
                    carry = 1;
                    break;
            }
        }
        if (carry == 1)
            Ans.push_back('1');
        reverse(Ans.begin(), Ans.end()); 
        return Ans;
    }
};

int main()
{
    string a = "110";
    string b = "0";
    Solution sol;
    cout << sol.addBinary(a,b);
}