/*
time complexity: O(n*logk), k = tasks.length
tags: Array, Hash Table, Greedy, Sorting, Heap(Priority Queue), Counting
note: 因為 letter 排入後需要等待才能再次排入，所以出現次數較多的 letter 越早排入越好
1. 計算每個 letter 出現的次數
2. 將 letters 放進 maxHeap
3. 建立一個管理 letter idle 時間的 Queue，資料格式為：{下一個可以被排入的時間, 該 letter 剩下的次數}
4. 在 while 迴圈內累加時間，並持續將 letter 放進 idle Queue，以及將 idle 時間到的 letter 出現次數放回 maxHeap
*/

class Solution
{
public:
    int leastInterval(vector<char> &tasks, int n)
    {

        // 計算每個 letter 出現的次數
        unordered_map<char, int> freqMap;
        for (char &letter : tasks)
        {
            freqMap[letter]++;
        }

        // 將 letters 放進 maxHeap
        priority_queue<int> maxHeap;
        for (auto pair : freqMap)
        {
            maxHeap.push(pair.second);
        }

        int time = 0;
        // 建立一個管理 letter idle 時間的 Queue
        queue<pair<int, int>> idleQueue; // {下一個可以被排入的時間, 該 letter 剩下的次數}

        while (!maxHeap.empty() || !idleQueue.empty())
        {
            time++;

            if (!maxHeap.empty())
            {
                int currentFreq = maxHeap.top();
                maxHeap.pop();
                currentFreq--;
                if (currentFreq > 0)
                {
                    idleQueue.push({time + n, currentFreq});
                }
            }

            // 若該 letter 的 idle 時間到了，則在把它的出現次數加入 maxHeap
            if (!idleQueue.empty() && idleQueue.front().first == time)
            {
                maxHeap.push(idleQueue.front().second);
                idleQueue.pop();
            }
        }

        return time;
    }
};