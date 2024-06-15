/*
time complexity: O(n)
tags: Two Pointer, String
note: 用 Two pointer 指向頭與尾的 char 逐個比較
*/

#include <iostream>
#include <string>
#include <cwctype>
#include <cctype>
using namespace std;

class Solution
{
public:
    bool isPalindrome(string s)
    {
        int pointer1 = 0, pointer2 = s.length() - 1;
        while (pointer1 <= pointer2)
        {
            while (!iswalnum(s[pointer1]) && pointer1 < s.length() - 1)
                pointer1++;
            while (!iswalnum(s[pointer2]) && pointer2 > 0)
                pointer2--;

            if (pointer1 > pointer2)
                break;

            if (tolower(s[pointer1]) != tolower(s[pointer2]))
                return false;

            pointer1++;
            pointer2--;
        }
        return true;
    }
};
// ab bv b, b a