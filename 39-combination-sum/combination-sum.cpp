class Solution {
private:
    vector<vector<int>> res;
    int tar;
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        res.clear();
        tar = target;
        dfs(0, 0, {}, candidates);
        return res;
    }
    void dfs(int i,int total, vector<int> curr, vector<int>& candidates) {
        // basecases
        if (total==tar) {res.push_back(curr); return;}
        if (i>=candidates.size() || total>tar) return;

        total += candidates[i];
        curr.push_back(candidates[i]);
        dfs(i, total, curr, candidates);

        curr.pop_back();
        total -= candidates[i];
        dfs(i+1, total, curr, candidates);
    }
};