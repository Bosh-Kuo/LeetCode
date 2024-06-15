/*
time complexity: O(numStrings * stringLength)
tags: Array, String, Divide and Conquer, Sorting, Heap(Priority Queue), Radix Sort, Quick select
note: 用一個二維陣列儲存每個 radix 排序後的 index，查詢時再一一選出在底幾 radix 下，第幾小的 index
*/

class Solution
{
public:
    int charToIntAtPosition(string &str, int position)
    {
        return str[str.size() - position] - '0';
    }
    vector<int> smallestTrimmedNumbers(vector<string> &nums, vector<vector<int>> &queries)
    {
        int numStrings = nums.size();      // 數字字串數量
        int stringLength = nums[0].size(); // 每個字串的長度(digits 數量)

        // 建立一個二維陣列儲存 nums 在每個 digit 下，元素由小排到大後的 index
        // ex: nums = [2, 5, 1, 3] => [2, 0, 3, 1]
        vector<vector<int>> indexSortedByRadix(stringLength + 1, vector<int>(numStrings, 0));

        // digit 為 0 時，可以視為初始還未排序時， index 順序為 [0, 1, 2, ..., numStrings - 1]
        iota(indexSortedByRadix[0].begin(), indexSortedByRadix[0].end(), 0);

        // 對每個 radix 進行排序
        for (int radix = 1; radix <= stringLength; radix++)
        {
            // 用於計算 0 ~ 9 每個數字出現的次數
            vector<int> countDigits(10, 0);
            for (int i = 0; i < numStrings; i++)
                ++countDigits[charToIntAtPosition(nums[i], radix)];

            // 計算 0 ~ 9 每個數字的起始位置
            // ex: countDigits = [0,1,2,0,1,1,2,0,2,1] => countDigits = [0,0,1,3,3,4,5,7,7,9]
            int index = 0;
            for (int &count : countDigits)
            {
                int temp = count;
                count = index;
                index += temp;
            }

            // 更新排序後的 index
            vector<int> newSortedIndex(numStrings, 0);
            for (int i = 0; i < numStrings; i++)
            {
                int prevIndex = indexSortedByRadix[radix - 1][i];        //  前一個 radix 排序後第 i 小的 nums 元素 index
                int digit = charToIntAtPosition(nums[prevIndex], radix); //  前一個 radix 排序後第 i 小的 nums 元素在第 radix 個 digit 上的值
                newSortedIndex[countDigits[digit]] = prevIndex;          // 將前一個 radix 排序後第 i 小的 nums 元素 index放置在這一輪的正確位置上
                countDigits[digit]++;
            }
            indexSortedByRadix[radix] = newSortedIndex;

            // 處理 query
            vector<int> results(queries.size());
            for (int i = 0; i < queries.size(); ++i)
            {
                int k = queries[i][0];     // 查詢的第 k 小的數字
                int radix = queries[i][1]; // 查詢的基數位
                results[i] = indexSortedByRadix[radix][k - 1];
            }
            return results;
        }
    }
};