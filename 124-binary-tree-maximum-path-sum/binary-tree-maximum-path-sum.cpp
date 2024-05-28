class Solution {
public:
    int maxPathSum(TreeNode* root) {

        int maxSum = INT_MIN;
        calculateMaxSum(root, maxSum);
        return maxSum;
    }
    int calculateMaxSum(TreeNode* node, int& maxSum) {
        if (!node) return 0;

        int leftSum = max(calculateMaxSum(node->left, maxSum), 0);
        int rightSum = max(calculateMaxSum(node->right, maxSum), 0);

        int currentSum = node->val + leftSum + rightSum;
        maxSum = max(maxSum, currentSum);
        return node->val + max(leftSum, rightSum);
    }
};