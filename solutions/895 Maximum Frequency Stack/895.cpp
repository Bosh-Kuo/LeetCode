/*
time complexity: O(log(n))
tags: Hash Table, Stack, Design, Ordered Set
note: 使用 maxHeap(priority_queue) 儲存該數被 push 時{出現的次數, 加入時間, 值}，利用 maxHeap 的特性，
pop 時會優先 pop 出現的次數較大者，若遇到相同出現的次數者，則會優先 pop 加入時間較晚者
*/

class FreqStack
{
public:
    int global_order = 0;
    unordered_map<int, int> freqMap;
    priority_queue<pair<int, pair<int, int>>> pq; // {freq, {ordered, value}}
    FreqStack()
    {
    }

    void push(int val)
    {
        freqMap[val]++;
        pq.push({freqMap[val], {global_order, val}});
        global_order++;
    }

    int pop()
    {
        int val = pq.top().second.second;
        freqMap[val]--;
        pq.pop();
        return val;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */