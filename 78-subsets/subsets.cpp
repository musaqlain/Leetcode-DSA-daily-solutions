class Solution {
public:
    vector<vector<int>> subset;
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> current;
        int i = 0;
        dfs(nums, current, i);
        return subset;
    }
    void dfs(vector<int>& nums, vector<int> current, int i) {
        if (i>=nums.size()) {
            subset.push_back(current);
            return;
        }
        current.push_back(nums[i++]);
        dfs(nums, current, i);

        current.pop_back();
        dfs(nums, current, i);
    }
};