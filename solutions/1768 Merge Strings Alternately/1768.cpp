/*
time complexity : O(n)
tags: String, Two Pointers
note: 先找出最長的字串長度，再依照該長度執行 for loop
*/

class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int length = word1.length() > word2.length() ? word1.length() : word2.length();
        string answer = "";
        for(int i = 0; i < length; i++)
        {
            if(i < word1.length())
                answer += word1[i];
            if(i < word2.length())
                answer += word2[i];                
        }
        return answer;
    }
};