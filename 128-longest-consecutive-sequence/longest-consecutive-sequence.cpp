class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        const int n = nums.size();
        if (n == 0) return 0;
        sort(nums.begin(), nums.end());

        int count=1, large=1;

        for (int i=1; i<n; i++) {
            if (nums[i]-1 == nums[i-1]) {
                count++;
                large = max(large, count);
            } else if (nums[i-1] != nums[i]) {
                count = 1;
            }
        }

        return large;
    }
};