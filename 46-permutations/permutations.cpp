class Solution {
private:
    vector<vector<int>> res;
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> ds;
        vector<int> fs(nums.size(), 0);
        dfs(nums, ds, fs);
        return res;
    }
    void dfs(vector<int>& nums, vector<int> ds, vector<int>& fs) {
        // base condition
        if (ds.size() == nums.size()) {
            res.push_back(ds);
            return;
        }

        // logic
        for (int i=0; i<nums.size(); i++) {
            if (!fs[i]) {
                ds.push_back(nums[i]);
                fs[i] = 1;
                dfs(nums, ds, fs);

                fs[i] = 0;
                ds.pop_back();
            }
        }
    }
};