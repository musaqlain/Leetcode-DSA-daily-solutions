class Solution {
public:
    int maxProduct(vector<int>& nums) {
        const int n = nums.size();
        double suf = 1, pre = 1, ans = INT_MIN;

        for (int i=0; i<n; i++) {
            // handling zeros
            if (pre == 0) pre = 1;
            if (suf == 0) suf = 1;

            // handling arrays with odd -ve elements
            pre *= nums[i];
            suf *= nums[n-1-i];

            ans = max({ans, pre, suf});
            
        }

        return ans;
    }
};