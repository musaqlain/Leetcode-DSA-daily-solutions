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
    int depth(TreeNode* node) {
        // base case
        if (!node) return 0;
        return 1+max(depth(node->left), depth(node->right));
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        // base case
        if (!root) return 0;

        int leftDepth = depth(root->left);
        int rightDepth = depth(root->right);

        int rootDiameter = leftDepth+rightDepth;
        int leftDiameter = diameterOfBinaryTree(root->left);
        int rightDiameter = diameterOfBinaryTree(root->right);

        return max({rootDiameter, leftDiameter, rightDiameter});
    }
};