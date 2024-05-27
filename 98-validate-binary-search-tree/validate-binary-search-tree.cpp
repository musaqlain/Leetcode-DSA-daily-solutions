class Solution {
public:
    bool isValidBST(TreeNode* root) {
        bool ans = true;
        dfs(root, {static_cast<long long>(INT_MIN)-1,static_cast<long long>(INT_MAX)+1}, ans);
        return ans;
    }
    void dfs(TreeNode* node, pair<long long, long long> range, bool& ans) {
        if (!node || !ans) return;

        if (node->val<=range.first || node->val>=range.second) {
            ans = false;
            return;
        } else {
            dfs(node->left, {range.first, node->val}, ans);
            dfs(node->right, {node->val, range.second}, ans);
        }
    }
};