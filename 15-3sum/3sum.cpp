class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        const int size = nums.size();
        sort(nums.begin(), nums.end());

        set<vector<int>> st;
        vector<vector<int>> res;

        for (int i = 0; i < size - 2; i++) {
            int low = i + 1, high = size - 1;
            while (low < high) {
                if (nums[i] + nums[low] + nums[high] < 0) {
                    low++;
                } else if (nums[i] + nums[low] + nums[high] > 0) {
                    high--;
                } else {
                    st.insert({nums[i], nums[low], nums[high]});
                    low++, high--;
                }
            }
        }

        for (auto it : st) {
            res.push_back(it);
        }

        return res;
    }
};
