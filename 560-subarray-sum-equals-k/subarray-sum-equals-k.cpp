class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> prefixSumCount;

        int currentSum = 0;
        int count = 0;

        // Initialize the hash map with a prefix sum of 0 (empty subarray).
        prefixSumCount[0] = 1;

        for (int i = 0; i < n; i++) {
            currentSum += nums[i];

            // Check if the complement exists in the hash map.
            if (prefixSumCount.find(currentSum - k) != prefixSumCount.end()) {
                count += prefixSumCount[currentSum - k];
            }

            // Update the hash map with the current prefix sum.
            prefixSumCount[currentSum]++;
        }

        return count;
    }
};
