class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        int minVal = nums[0];

        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] < minVal) {
                minVal = nums[mid];
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        return minVal;
    }
};