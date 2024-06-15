/*
time complexity: O(nlog(n))
tags: Hash Table, String, Sorting
note: 將兩字串排序後相比即可
*/
#include <iostream>
#include <string>

using namespace std;


class Solution {
public:
    bool isAnagram(string s, string t) 
    {
        sort(s.begin(), s.end(), less<char>());
        sort(t.begin(), t.end(), less<char>());
        if (s==t)
            return true;
        else
            return false;
    }
};