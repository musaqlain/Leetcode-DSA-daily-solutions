class Solution {
private:
    vector<vector<int>> res;
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> curr;
        dfs(curr, 0, nums);
        return res;
    }
    void dfs(vector<int>& curr, int i, vector<int>& nums) {
        if (i>=nums.size()) {
            res.push_back(curr);
            return;
        }

        curr.push_back(nums[i]);
        dfs(curr, i+1, nums);

        curr.pop_back();
        dfs(curr, i+1, nums);
    }
};