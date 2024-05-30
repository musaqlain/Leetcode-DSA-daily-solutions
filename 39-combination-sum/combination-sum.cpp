class Solution {
private:
    vector<vector<int>> res;

public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        res.clear();
        vector<int> curr;
        dfs(0, target, curr, candidates);
        return res;
    }
    void dfs(int i, int target, vector<int>& curr, vector<int>& candidates) {
        // basecases
        if (target == 0) {
            res.push_back(curr);
            return;
        }
        if (i >= candidates.size() || target < 0)
            return;

        curr.push_back(candidates[i]);
        dfs(i, target - candidates[i], curr, candidates);

        curr.pop_back();
        dfs(i + 1, target, curr, candidates);
    }
};