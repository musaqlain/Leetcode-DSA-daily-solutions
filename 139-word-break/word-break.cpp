class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int i = 0;
        const int n = s.size();
        vector<int> dp(n+1, -1);
        return dfs(i, s, wordDict, n, dp);
    }

    bool dfs(int i, string& s, vector<string>& wordDict, const int n, vector<int>& dp) {
        // base
        if (i >= n)
            return true;

        if (dp[i] != -1) return dp[i];

        for (int j = 0, len = wordDict.size(); j < len; j++) {
            int l = wordDict[j].size();
            if (i + l <= n && s.substr(i, l) == wordDict[j]) {
                if (dfs(i + l, s, wordDict, n, dp)) {
                    dp[i] = 1;
                    return true;
                }
            }
        }

        dp[i] = 0;
        return false;
    }
};