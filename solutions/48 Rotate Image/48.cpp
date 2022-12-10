/*
time complexity: O(n^2)
tags: Array, Math, Matrix
note: 從最外層開始一層一層解決，依照方形的四個邊依序 左 -> 上，下 -> 左，右 -> 下，上 -> 右
*/

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int length = matrix.size();  // 矩陣邊長
        int layers = matrix.size() / 2;  // 要處理的層數

        // 從最外層開始旋轉，x, y 範圍：[0+layer, length-1-layer], [0+layer, length-1-layer]
        for (int layer = 0; layer < layers; layer++)
        {
            // 一層中單排要處理的元數個數
            for (int i = 0; i < length - layer * 2 - 1; i++)
            {
                int temp = matrix[0+layer][0+layer+i];
                matrix[0+layer][0+layer+i] = matrix[length-1-layer-i][0+layer];  // 左 -> 上
                matrix[length-1-layer-i][0+layer] = matrix[length-1-layer][length-1-layer-i];  // 下 -> 左
                matrix[length-1-layer][length-1-layer-i] = matrix[0+layer+i][length-1-layer];  // 右 -> 下
                matrix[0+layer+i][length-1-layer] = temp;
            }            
        }
    }
};