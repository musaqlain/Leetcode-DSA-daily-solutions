class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(n+1, -1);
        return dfs(n, 0, dp);
    }

    int dfs(int n, int start, vector<int> &dp) {
        if (start > n) return 0;
        if (start == n) return 1;

        if (dp[start]!=-1) return dp[start];

        dp[start] = dfs(n,start+1, dp) + dfs(n,start+2, dp);

        return dp[start];
    }
};