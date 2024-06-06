class Solution {
private:
    vector<vector<int>> res;
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> curr;
        sort(nums.begin(), nums.end());
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
        while (i+1<nums.size() && nums[i] == nums[i+1]) i+=1;
        dfs(curr, i+1, nums);
    }
};