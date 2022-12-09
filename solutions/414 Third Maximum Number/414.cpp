/*
time complexity: O(n)
tags: Array, Sorting
note: 用 min heap 跟 unordered set 來解。維持一個大小為 3 的 min heap，最上面的 element 會是最小的數，當有一數比 min heap 中最小的的數還大時，剔除 min heap 最小的數，並加入該數。
unordered set 則是用來記錄已經出現過的數，當一數出現已經出現過一次就跳過它。
*/

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
using namespace std;

class Solution
{
public:
    int thirdMax(vector<int> &nums)
    {
        priority_queue<int, vector<int>, greater<int>> minHeap;
        unordered_set<int> taken;
        for (auto num : nums)
        {
            // 若這個數已經出現過就跳過
            if (taken.count(num))
                continue;

            // 移除 minHeap 最小的數
            if (minHeap.size() == 3)
            {
                if (minHeap.top() < num)
                {
                    minHeap.pop();
                    minHeap.push(num);
                    taken.insert(num);
                }
            }
            else
            {
                minHeap.push(num);
                taken.insert(num);
            }
        }
        if(minHeap.size() == 1 || minHeap.size() == 3)
            return minHeap.top();
        else
        {
            minHeap.pop();
            return minHeap.top();
        }
    }
};

int main()
{
    vector<int> nums = {3,2,1,5};
    Solution sol;
    cout << sol.thirdMax(nums);
}
