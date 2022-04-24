
void heapify(int* nums, int idx, int length)
{
    int leftIdx = 2*idx + 1;
    int rightIdx = 2*idx + 2;
    int largestIdx = idx;
    if(leftIdx < length && nums[leftIdx]>nums[largestIdx])
         largestIdx = leftIdx;
    if(rightIdx < length && nums[rightIdx]>nums[largestIdx])
        largestIdx = rightIdx;
    if(largestIdx != idx)
    {
     int temp = nums[idx];
     nums[idx] = nums[largestIdx];
     nums[largestIdx] = temp;
     heapify(nums, largestIdx, length);
    }
}

int findKthLargest(int* nums, int numsSize, int k){
    for (int i = numsSize/2 - 1; i >= 0; i--)
        heapify(nums, i, numsSize);
    int target = 0;
    for (int i = 0; i < k; i++)
    {
        target = nums[0];
        nums[0] = -10000;
        heapify(nums, 0, numsSize);
    }
    return target;
}