/*
time complexity: O(n)
tags: Two Pointers Design, Sorting, Heap(Priority Queue), Data Stream
note: 維護一個 minHeap, 一個 maxHeap 使兩者 size 相差不超過 1。
minHeap 存最大的一半(由小排到大)， maxHeap 存最小的一半(由大排到小)，
中位數可由 minHeap, maxHeap 的 top 來決定
*/

class MedianFinder
{
private:
    priority_queue<int, vector<int>, greater<int>> minHeap; // 最大的一半(由小排到大)
    priority_queue<int> maxHeap;                            // 最小的一半(由大排到小)

public:
    MedianFinder() {}

    void addNum(int num)
    {
        if (maxHeap.empty() || num < maxHeap.top())
            maxHeap.push(num);
        else
            minHeap.push(num);

        // 平衡兩 heap 的 size
        if (maxHeap.size() > minHeap.size() + 1)
        {
            int max = maxHeap.top();
            minHeap.push(max);
            maxHeap.pop();
        }
        else if (minHeap.size() > maxHeap.size() + 1)
        {
            int min = minHeap.top();
            maxHeap.push(min);
            minHeap.pop();
        }
    }

    double findMedian()
    {
        if (maxHeap.size() == minHeap.size())
        {
            if (maxHeap.empty())
            {
                return 0;
            }
            else
            {
                double avg = (maxHeap.top() + minHeap.top()) / 2.0;
                return avg;
            }
        }
        else
        {
            return maxHeap.size() > minHeap.size() ? maxHeap.top() : minHeap.top();
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
