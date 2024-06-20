class Solution {
private:
    int maxSum(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];

        int prev2 = nums[0];
        int prev1 = max(nums[0], nums[1]);

        for (int i=2; i<n; i++) {
            int curr = max(nums[i]+prev2, prev1);
            prev2 = prev1;
            prev1 = curr;
        }

        return prev1;
    }
public:
    int rob(vector<int>& nums) {
        vector<int> subArr1, subArr2;
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];
        for (int i=0; i<n; i++) {
            if (i!=0) {
                subArr1.push_back(nums[i]);
            }
            if (i!=n-1) {
                subArr2.push_back(nums[i]);
            }
        }

        return max(maxSum(subArr1), maxSum(subArr2));
    }
};