class Solution {
public:
    int climbStairs(int n) {
        if (n==1) return 1;
        vector<int> dp(n+1, -1);
        return dfs(n, 0, dp);
    }

    int dfs(int n, int total, vector<int>& dp) {
        // base cases
        if (total == n) {
            return 1;
        }
        if (total > n) return 0;

        if (dp[total] != -1) return dp[total];

        return dp[total] = dfs(n, total+1, dp) + dfs(n, total+2, dp);
    }
};