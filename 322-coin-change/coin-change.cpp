class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        const int n = coins.size();
        int ind = n - 1;
        vector<vector<int>> dp(n, vector<int>(amount+1, -1));
        int ans = dfs(coins, ind, amount, dp);

        if (ans >= 1e9) return -1;
        return ans;
    }
    int dfs(vector<int>& coins, int ind, int amount, vector<vector<int>>& dp) {
        // base-case
        if (ind == 0) {
            if (amount%coins[0] == 0) return amount/coins[0];
            return 1e9;
        }

        // leverage memoization
        if (dp[ind][amount] != -1) return dp[ind][amount]; 

        // Explaore all the ways
        // not-taken  
        int notTaken = 0+dfs(coins, ind-1, amount, dp);

        // taken
        int taken = INT_MAX;
        if (coins[ind] <= amount) {
            taken = 1+dfs(coins, ind, amount-coins[ind], dp);
        }

        return dp[ind][amount] = min(notTaken, taken);
    }
};