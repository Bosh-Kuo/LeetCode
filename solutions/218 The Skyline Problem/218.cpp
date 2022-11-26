/*
time complexity : O(nlog(n))
tags: Array, Divide and Conquer Binary Indexed Tree, Segment Tree, Line Sweep, Heap(Priority Queue) Ordered Set
note:
由於我們需要走訪每一個點，我們需要串見一個 points array 來儲存每個點的 (x,y)，為了方便辨識該點是一棟樓的 start point or end point，
我們將 start point 的 y 值存成負數，當 current point 為負，我們將此加入 fallback list，當 current point 為正，代表該點為結束點該樓高無法成為 fallback height，
必須將該樓高移除 fallback list。
fallback list  以 multiset 來實作，multiset 可以存重複的值，並且會從小排到大。
當目前最高的高度與 fallback list 中最高的高度相同時，代表當前最高的高度不需改變。若不同的話則代表當前最高的高度需要改變，並且作為一個紀錄點。

reference: https://leetcode.com/problems/the-skyline-problem/discuss/2094329/C%2B%2B-Easiest-Explanation-Ever-Guaranteed-Beginner-Friendly-Detailed-O(nlogn)
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <set>
#include <cmath>
using namespace std;

class Solution
{
public:
    vector<vector<int>> getSkyline(vector<vector<int>> &buildings)
    {
        vector<pair<int, int>> points;
        multiset<int> fallbackHeights;
        fallbackHeights.insert(0);
        vector<vector<int>> Ans;
        int highestHeight = 0;

        // 將所有點存成 sorted point vector
        for (vector<int> building : buildings)
        {
            points.push_back({building[0], -building[2]}); // start 標負
            points.push_back({building[1], building[2]});  // end 標負
        }
        sort(points.begin(), points.end());

        // 遍歷每個 point
        for (int i = 0; i < points.size(); i++)
        {
            int currentX = points[i].first;
            int currentY = points[i].second;

            // 若為 start point 就加入 fallbackList
            if (currentY < 0)
                fallbackHeights.insert(abs(currentY));
            // 若為 end point 就從 fallbackList 移除
            else
                fallbackHeights.erase(fallbackHeights.find(currentY));

            // 若 fallbackHeights 中最高的 height 跟當前最高的點不相同，即為一個紀錄點
            int fallbackTop = *fallbackHeights.rbegin();
            if (highestHeight != fallbackTop)
            {
                highestHeight = fallbackTop;
                Ans.push_back({currentX, highestHeight});
            }
        }
        return Ans;
    }
};

int main()
{
    vector<vector<int>> buildings = {{2, 9, 10}, {3, 7, 15}, {5, 12, 12}, {15, 20, 10}, {19, 24, 8}};
    Solution sol;
    vector<vector<int>> Ans = sol.getSkyline(buildings);
    for (auto point : Ans)
    {
        cout << point[0] << " " << point[1] << endl;
    }
}