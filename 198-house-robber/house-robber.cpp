class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size() + 1, -1);
        return dfs(0, nums, dp);
    }

    int dfs(int i, vector<int>& nums, vector<int>& dp) {
        // basecases
        if (i>=nums.size()) return 0;
        if (i==nums.size()-1) return nums[i];

        if (dp[i]!=-1) return dp[i];

        int left = nums[i] + dfs(i+2, nums, dp);
        int right = dfs(i+1, nums, dp);

        return dp[i] = max(left, right);
    }
};