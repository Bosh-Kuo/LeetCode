/*
time complexity : O(n)
tags: Math, String
note: 如果說 str1, str2 有公約數的話，那 str1+str2 會等於 str2+str1
ex: str1 = "ABCABCABC", str2 = "ABC"
可用兩者長度來計算最大公約數
*/

class Solution
{
public:
    string gcdOfStrings(string str1, string str2)
    {
        if (str1 + str2 == str2 + str1)
            return str1.substr(0, gcd(str1.length(), str2.length()));
        return "";
    }
};