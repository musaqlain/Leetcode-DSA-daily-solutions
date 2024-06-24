class Solution {
public:
    int minOperations(vector<int>& nums) {
        int count = 0;
        int flag = 0;

        for (int i=0, len=nums.size(); i<len; i++) {
            if ((nums[i] - flag) == 0) {
                count++;
                flag = 1 - flag;
            }
        }

        return count;
    }
};