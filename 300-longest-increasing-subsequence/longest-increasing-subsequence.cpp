class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        const int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n+1, -1));
        return dfs(0, -1, nums, dp);
    }
    int dfs(int i, int prev, vector<int>& nums, vector<vector<int>>& dp) {
        if (i == nums.size()) return 0;
        if (dp[i][prev+1] != -1) return dp[i][prev+1];

        int len = 0 + dfs(i+1, prev, nums, dp);
        if (prev == -1 || nums[i] > nums[prev]) {
            len = max(len, 1 + dfs(i+1, i, nums, dp));
        }

        return dp[i][prev+1] = len;
    }
};