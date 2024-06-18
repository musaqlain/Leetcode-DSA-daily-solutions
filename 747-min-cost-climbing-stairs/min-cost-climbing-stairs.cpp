class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp(cost.size() + 1, -1);
        return min(dfs(cost, cost.size()-1, dp), dfs(cost, cost.size()-2, dp));
    }

    int dfs(vector<int>& cost, int i, vector<int>& dp) {
        // basecases
        if (i<0) return 0;
        if (i==0 || i==1) return cost[i];

        if (dp[i] != -1) return dp[i];

        // recursively
        return dp[i] = cost[i] + min(dfs(cost, i-1, dp), dfs(cost, i-2, dp));
    }
};