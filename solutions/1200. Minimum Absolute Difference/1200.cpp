/*
time complexity : O(nlog(n))
tags: Array, Sorting
note: 嘗試用 heap sort
*/

class Solution
{
public:
    void heapSort(vector<int> &arr)
    {
        for (int i = arr.size() / 2 - 1; i >= 0; i--)
        {
            maxHeapify(arr, arr.size(), i);
        }

        for (int i = arr.size() - 1; i > 0; i--)
        {
            // swap last element with first element
            int temp = arr[i];
            arr[i] = arr[0];
            arr[0] = temp;
            // note that we reduce the heap size by 1 every iteration
            maxHeapify(arr, i, 0);
        }
    }
    void maxHeapify(vector<int> &arr, int heapSize, int index)
    {
        int left = 2 * index + 1;
        int right = 2 * index + 2;
        int largest = index;
        if (left < heapSize && arr[left] > arr[largest])
        {
            largest = left;
        }
        if (right < heapSize && arr[right] > arr[largest])
        {
            largest = right;
        }
        if (largest != index)
        {
            int temp = arr[index];
            arr[index] = arr[largest];
            arr[largest] = temp;
            maxHeapify(arr, heapSize, largest);
        }
    }
    vector<vector<int>> minimumAbsDifference(vector<int> &arr)
    {
        heapSort(arr);
        vector<vector<int>> answer;
        int minimum = 10000000;
        for (int i = arr.size() - 1; i > 0; i--)
        {
            if (minimum > arr[i] - arr[i - 1])
                minimum = arr[i] - arr[i - 1];
        }
        for (int i = 0; i < arr.size() - 1; i++)
        {
            if (arr[i + 1] - arr[i] == minimum)
                answer.push_back({arr[i], arr[i + 1]});
        }
        return answer;
    }
};