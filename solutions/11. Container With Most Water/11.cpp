/*
time complexity: O(n)
tags: Array, Two Pointers, Greedy
note: 直覺上長方形長度愈長高度愈高可圍城的面積就愈大，理想上最外圍的兩個高度分別是前兩高可以為出最大的長方形。在長度變小的狀況下可以求得更大面積的長方形的情況只有使用的高度變高，
由於長方形的高度受左右邊界元素高度較小者決定，因此讓長方形高度上升的唯一方法就是捨棄將高度較小的邊界，向內找高度更高的元素。才有機會讓原本高度比較高的邊界成為新的長方形高度
*/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int calculateArea(int left, int right, int height)
    {
        return (right - left) * height;
    }
    int maxArea(vector<int>& height) 
    {
        int left = 0, right = height.size() - 1;
        int max = 0;
        while (left < right)
        {
            int rectangleHeight = height[left] < height[right] ? height[left] : height[right];
            int area = calculateArea(left, right, rectangleHeight);
            max = area > max ? area : max;
            if (height[left] > height[right])
                right --;
            else
                left ++;
        }
        return max;
    }
};