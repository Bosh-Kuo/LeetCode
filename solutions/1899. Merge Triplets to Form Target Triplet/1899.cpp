/*
time complexity : O(n)
tags: Array, Greedy
note: 遍歷 triplets，更新 mergedTriplet
*/

class Solution
{
public:
    bool mergeTriplets(vector<vector<int>> &triplets, vector<int> &target)
    {
        vector<int> mergedTriplet(3, 0);

        for (const auto &triplet : triplets)
        {
            if (triplet[0] > target[0] || triplet[1] > target[1] || triplet[2] > target[2])
            {
                continue;
            }

            mergedTriplet[0] = max(mergedTriplet[0], triplet[0]);
            mergedTriplet[1] = max(mergedTriplet[1], triplet[1]);
            mergedTriplet[2] = max(mergedTriplet[2], triplet[2]);

            if (mergedTriplet == target)
            {
                return true;
            }
        }

        return false;
    }
};
