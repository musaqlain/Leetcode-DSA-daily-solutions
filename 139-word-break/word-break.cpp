class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        const int n = s.size();
        vector<bool> dp(n+1, false);

        dp[n] = true;

        for (int i=n-1; i>=0; i--) {
            for (int w=0, len=wordDict.size();w<len; w++) {
                int l = wordDict[w].size();
                if (i+l <= n && s.substr(i, l) == wordDict[w]) {
                    dp[i] = dp[i + l];
                }
                if (dp[i]) break;
            }
        }

        return dp[0];
    }
};