class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int S = 0;
        const int n = nums.size();
        for (int i=0; i<n; i++) {
            S += nums[i];
        }

        if (S%2 != 0) return false;

        vector<vector<int>> dp(n+1, vector<int>(S/2+1, -1));

        return dfs(0, 0, nums, S, n, dp);
    }

    bool dfs(int i, int sum, vector<int>& nums, int S, int n, vector<vector<int>>& dp) {
        // base
        if (i >= n) return false;
        if (sum == S/2) return true;
        if (sum > S/2) return false;

        if (dp[i][sum] != -1) return dp[i][sum];

        // logic
        bool l = dfs(i+1, sum, nums, S, n, dp); // not-taken
        bool r = dfs(i+1, sum+nums[i], nums, S, n, dp); // taken

        return dp[i][sum] = l || r;
    }
};