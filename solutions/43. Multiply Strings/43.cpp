/*
time complexity : O(n*m)
tags: Math, String, Simulation
note: 先創建一個長度為兩輸入字串長度和且都是 '0' 的 string，逐位數進行乘法填入當前指向的位數，若需要進位則持續填入下一個位數直到不虛進位為止
*/

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution
{
public:
    string multiply(string num1, string num2)
    {
        string Ans(num1.length() + num2.length(), '0');

        for (int i = num1.length() - 1; i >= 0; i--)
        {
            for (int j = num2.length() - 1; j >= 0; j--)
            {
                // 目前要填的的位數
                int currentDigit = (num1.length() - 1) - i + (num2.length() - 1) - j;

                // 該位數的乘積、填入值、進位數
                int product = (num1[i] - '0') * (num2[j] - '0');
                int num = product % 10;
                int carry = product / 10;

                // 填入該位數
                int currentNum = (num + (Ans[currentDigit] - '0')) % 10;
                carry += (num + (Ans[currentDigit] - '0')) / 10;
                Ans[currentDigit] = '0' + currentNum;

                // 若有進位要繼續填
                while (carry != 0)
                {
                    currentDigit++;
                    currentNum = (carry + (Ans[currentDigit] - '0')) % 10;
                    carry = (carry + (Ans[currentDigit] - '0')) / 10;
                    Ans[currentDigit] = '0' + currentNum;
                }
            }
        }
        // 翻轉位數
        while (Ans[Ans.length() - 1] == '0' && Ans.length() > 1)
            Ans.pop_back();
        reverse(Ans.begin(), Ans.end());
        return Ans;
    }
};

int main()
{
    string num1 = "0", num2 = "0";
    Solution sol;
    cout << sol.multiply(num1, num2);
}