class Solution {
private:
    vector<vector<int>> res;
    void dfs(vector<int>& nums, vector<int>& current, int i) {
        if (i >= nums.size()) {
            res.push_back(current);
            return;
        }
        current.push_back(nums[i]);
        dfs(nums, current, i + 1);

        current.pop_back();
        dfs(nums, current, i + 1);
    }

public:
    vector<vector<int>> subsets(vector<int>& nums) {
        res.clear();
        res.reserve(1 << nums.size());
        vector<int> current;
        dfs(nums, current, 0);

        return res;
    }
};