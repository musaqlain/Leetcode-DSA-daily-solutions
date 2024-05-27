/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    int l = 0;
    int h = 0;
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        int res = 0;
        l = low, h = high;
        dfs(root, res);
        return res;
    }
    void dfs(TreeNode* node, int& res) {
        if (!node) return;
        if (node->val > h || node->val < l ) {
            if (node->val > h) dfs(node->left, res);
            if (node->val < l) dfs(node->right, res);
        } else {
            res += node->val;
            dfs(node->left, res);
            dfs(node->right, res);
        }

    }
};