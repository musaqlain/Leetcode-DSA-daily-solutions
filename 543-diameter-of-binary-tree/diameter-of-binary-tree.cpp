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
    int max_dia = 0;
    int traverseTree(TreeNode* node) {
        // basecases
        if (!node) return 0;
        if (node->left == NULL && node->right == NULL) return 1;

        int l=traverseTree(node->left);
        int r=traverseTree(node->right);

        max_dia = max(max_dia, l+r);

        return 1 + max(l, r);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        traverseTree(root);
        return max_dia;
    }
};