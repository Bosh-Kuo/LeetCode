/*
time complexity: O(1)
tags: Hash Table, Math, String
note:
*/

class Solution
{
public:
    string repeat(string s, int num)
    {
        string result = "";
        for (int i = 0; i < num; ++i)
        {
            result += s;
        }
        return result;
    }
    string thousandToRoman(int num)
    {
        if (num < 1000)
            return "";
        else
            return repeat("M", (num / 1000));
    }

    string hundredToRoman(int num)
    {
        int hundred = (num / 100) % 10;
        if (hundred >= 1 && hundred < 4)
            return repeat("C", (hundred));
        else if (hundred == 4)
            return "CD";
        else if (hundred >= 5 && hundred < 9)
            return "D" + repeat("C", hundred - 5);
        else if (hundred == 9)
            return "CM";
        else
            return "";
    }

    string tenToRoman(int num)
    {
        int ten = (num / 10) % 10;
        if (ten >= 1 && ten < 4)
            return repeat("X", (ten));
        else if (ten == 4)
            return "XL";
        else if (ten >= 5 && ten < 9)
            return "L" + repeat("X", ten - 5);
        else if (ten == 9)
            return "XC";
        else
            return "";
    }

    string oneToRoman(int num)
    {
        int one = num % 10;
        if (one >= 1 && one < 4)
            return repeat("I", (one));
        else if (one == 4)
            return "IV";
        else if (one >= 5 && one < 9)
            return "V" + repeat("I", one - 5);
        else if (one == 9)
            return "IX";
        else
            return "";
    }

    string intToRoman(int num)
    {
        return thousandToRoman(num) + hundredToRoman(num) + tenToRoman(num) + oneToRoman(num);
    }
};