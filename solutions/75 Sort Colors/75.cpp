/*
time complexity : O(n)
tags: Array, Two Pointers, Sorting
note: counting sort 解決
*/
class Solution
{
public:
    void sortColors(vector<int> &nums)
    {
        int red = 0, white = 0, blue = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            switch (nums[i])
            {
            case 0:
                red++;
                break;
            case 1:
                white++;
                break;
            default:
                blue++;
                break;
            }
        }
        for (int i = 0; i < nums.size(); i++)
        {
            if (red > 0)
            {
                nums[i] = 0;
                red--;
                continue;
            }
            else if (white > 0)
            {
                nums[i] = 1;
                white--;
                continue;
            }
            else
            {
                nums[i] = 2;
                blue--;
                continue;
            }
        }
    }
};