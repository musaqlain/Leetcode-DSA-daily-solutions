class Solution {
public:
    int numDecodings(string s) {
        int res = 0;
        int i = 0;
        const int n =s.size();
        vector<int> dp(n, 0);
        return dfs(s, i, n, dp);
    }

    int dfs(string& s, int i, const int n, vector<int>& dp) {
        // base-conditions
        if (i == n) return 1;
        if (s[i] == '0') return 0;
        // logic
        if (dp[i] != 0) return dp[i];
        int count = dfs(s, i+1, n, dp);
        if (i+1 < n && s.substr(i, 2) <= "26") {
            count += dfs(s, i+2, n, dp);
        }

        return dp[i] = count;
    }
};