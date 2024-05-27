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
public:
    bool isBalanced(TreeNode* root) {
        bool ans = true;
        getHT(root, ans);
        return ans;
    }
    int getHT(TreeNode* node, bool& ans) {
        if (!ans) return 0;
        if (!node) return 0;
        int lh = getHT(node->left, ans);
        int rh = getHT(node->right, ans);
        if (abs(lh-rh) > 1) ans = false;
        return 1 + max(lh, rh);
    }
};