class Solution {
public:
    bool isValidBST(TreeNode* root) {
        bool ans = true;
        dfs(root, {(long long)INT_MIN - 1, (long long)INT_MAX + 1}, ans);
        return ans;
    }
    void dfs(TreeNode* node, vector<long long> range, bool& ans) {
        if (!node) return;
        if (!ans) return;

        if (node->val<=range[0] || node->val>=range[1]) {
            ans = false;
            return;
        } else {
            dfs(node->left, {range[0], node->val}, ans);
            dfs(node->right, {node->val, range[1]}, ans);
        }
    }
};