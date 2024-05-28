class Solution {
public:
    vector<int> values;
    int kthSmallest(TreeNode* root, int k) {
        dfs(root);
        // sort(values.begin(), values.end());
        return values[k-1];
    }
    void dfs(TreeNode* node) {
        if (!node) return;
        dfs(node->left);
        values.push_back(node->val);
        dfs(node->right);
    }
};