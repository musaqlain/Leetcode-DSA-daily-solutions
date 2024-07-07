class Solution {
public:
    int rob(vector<int>& nums) {
        const int n = nums.size();
        if (n == 0) return 0;
        if (n==1) return nums[0];
        int p1 = 0;
        int p2 = 0;
        int curr = 0;

        for (int i=0; i<n;i++) {
            curr = max(p1, p2 + nums[i] );
            p2 = p1;
            p1 = curr;
        }

        return curr;
    }
};