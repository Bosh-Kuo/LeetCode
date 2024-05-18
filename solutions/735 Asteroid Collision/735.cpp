/*
time complexity: O(n)
tags: Array, Stack, Simulation
note: 使用 Stack FILO 特性，決定發生 collide 時保留左側或右側元素
*/

class Solution
{
public:
    vector<int> asteroidCollision(vector<int> &asteroids)
    {
        stack<int> s;
        vector<int> ans;
        for (auto asteroid : asteroids)
        {
            while (!s.empty())
            {
                int top = s.top();
                if (top * asteroid < 0 && top > 0)
                {
                    if (abs(asteroid) > abs(top))
                        s.pop();
                    else if (top + asteroid == 0)
                    {
                        s.pop();
                        asteroid = 0;
                        break;
                    }
                    else
                        break;
                }
                else
                {
                    s.push(asteroid);
                    break;
                }
            }
            if (s.empty() && asteroid != 0)
                s.push(asteroid);
        }

        while (!s.empty())
        {
            ans.push_back(s.top());
            s.pop();
        }
        reverse(ans.begin(), ans.end());

        return ans;
    }
};