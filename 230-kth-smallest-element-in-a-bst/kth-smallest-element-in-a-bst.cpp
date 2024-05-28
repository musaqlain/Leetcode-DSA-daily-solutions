class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        int result = -1;
        int count = 0;
        dfs(root, result, count, k);
        return result;
    }
    void dfs(TreeNode* node, int& result, int& count, int k) {
        if (!node || result != -1) return;
        dfs(node->left, result, count, k);
        count++;
        if (count == k) {
            result = node->val;
            return;
        }
        dfs(node->right, result, count, k);
    }
};