class Solution {
private:
    vector<vector<int>> result;
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> curr;
        unordered_set<int> st;
        dfs(nums, curr, st);
        return result;
    }
    void dfs(vector<int>& nums,vector<int>& curr, unordered_set<int>& st ) {
        // basecase
        if (curr.size() == nums.size()) {
            result.push_back(curr);
            return;
        }

        // logic
        for (int i=0; i<nums.size(); i++) {
            if (st.find(nums[i]) == st.end()) {
                st.insert(nums[i]);
                curr.push_back(nums[i]);
                dfs(nums, curr, st);

                st.erase(nums[i]);
                curr.pop_back();
            }
        }
    }
};