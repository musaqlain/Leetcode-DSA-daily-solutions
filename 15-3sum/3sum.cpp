class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        const int n = nums.size();
        vector<vector<int>> res;
        set<vector<int>> st;

        sort(nums.begin(), nums.end());

        for (int i = 0; i < n - 2; i++) {
            int low = i + 1, high = n - 1;

            while (low < high) {
                int sum = nums[i] + nums[low] + nums[high];
                if (sum == 0) {
                    st.insert({nums[i], nums[low], nums[high]});
                    low++, high--;
                } else if (sum < 0) {
                    low++;

                } else {
                    high--;
                }
            }
        }

        for (auto& triplet : st) {
            res.push_back(triplet);
        }

        return res;
    }
};