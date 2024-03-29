/*
time complexity: O(n)
tags: Math, String, Simulation
note:
*/

class Solution
{
public:
    vector<string> fizzBuzz(int n)
    {
        string fizz = "Fizz";
        string buzz = "Buzz";
        vector<string> ans;
        for (int i = 1; i <= n; i++)
        {
            if (i % 3 == 0 && i % 5 == 0)
                ans.push_back(fizz + buzz);
            else if (i % 3 == 0)
                ans.push_back(fizz);
            else if (i % 5 == 0)
                ans.push_back(buzz);
            else
                ans.push_back(to_string(i));
        }
        return ans;
    }
};