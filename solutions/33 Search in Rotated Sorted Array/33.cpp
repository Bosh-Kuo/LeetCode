/*
time complexity: O(log(n))
tags: Array, Binary Search
note: 這題比較大的數也可能出現在左邊，比較小的數也可能出現在右邊。若 target 比右邊任何數還大那可能出現在左邊，若 target 比左邊任何數還大那可能出現在右邊
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int left = 0, right = nums.size() - 1;
        while (left <= right)
        {
            int mid = (left + right) / 2;
            if(nums[mid] == target)
                return mid;
            
            // 若要找的數比 mid 大
            if(target > nums[mid])
            {
                // 若右邊界已經是右半邊最大，但如果 target 還是比右邊任何數還大，那可能在左邊
                if (nums[right] >= nums[mid] && target > nums[right])
                    right = mid - 1;
                else
                    left = mid + 1;
                    
            }
            // 若要找的數比 mid 小
            else
            {
                // 若左邊界已經是左半邊最小，但如果 target 還是比左邊任何數還小，那可能在右邊
                if (nums[left] <= nums[mid] && target < nums[left])                    
                    left = mid + 1;
                else
                    right = mid - 1;
            }
        }
        return -1;
    }
};

int main()
{
    vector<int> nums = {3,1};
    int target = 1;
    Solution sol;
    cout << sol.search(nums, target);
}