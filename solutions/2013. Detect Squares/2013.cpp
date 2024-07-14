/*
time complexity: O(n)
tags: Array, Hash Table, Design, Counting
note: 使用 map 紀錄每個座標出現的次數。遍歷 map 中的每個 key(座標)。先找出對頂點，再找出組成正方形剩餘兩點出現的次數
*/

class DetectSquares
{
public:
    map<pair<int, int>, int> coordMap;
    DetectSquares()
    {
    }

    void add(vector<int> point)
    {
        coordMap[{point[0], point[1]}]++;
    }

    int count(vector<int> point)
    {
        int count = 0;
        int targetX = point[0];
        int targetY = point[1];
        // 遍歷整個 map
        for (auto temp : coordMap)
        {
            pair<int, int> diagonal = temp.first;
            // 找對角線
            if (diagonal.first != targetX && diagonal.second != targetY && (abs(diagonal.first - targetX) == abs(diagonal.second - targetY)))
            {
                int freq1 = coordMap[{diagonal.first, diagonal.second}];
                int freq2 = coordMap[{targetX, diagonal.second}];
                int freq3 = coordMap[{diagonal.first, targetY}];
                count += freq1 * freq2 * freq3;
            }
        }
        return count;
    }
};

/**
 * Your DetectSquares object will be instantiated and called as such:
 * DetectSquares* obj = new DetectSquares();
 * obj->add(point);
 * int param_2 = obj->count(point);
 */