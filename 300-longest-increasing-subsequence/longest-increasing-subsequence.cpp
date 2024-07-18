class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        const int n = nums.size();
        vector<int> next(n+1, 0), current(n+1, 0);

        for (int i=n-1; i>=0; i--) {
            for (int prev=n-1; prev>=-1; prev--) {
                int len = 0 + next[prev+1];
                if (prev == -1 || nums[i] > nums[prev]) {
                    len = max(len, 1 + next[i+1]);
                }

                current[prev+1] = len;
            }

            next = current;
        }

        return current[0];
    }
};