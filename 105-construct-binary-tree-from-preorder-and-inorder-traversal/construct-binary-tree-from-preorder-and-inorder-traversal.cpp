class Solution {
private:
    vector<int> preorder;
    vector<int> inorder;
public:
    TreeNode* buildTree(vector<int>& pre_order, vector<int>& in_order) {
        for (int i:pre_order) preorder.push_back(i);

        unordered_map<int, int> hashMap;
        for (int i=0; i<in_order.size(); i++) {
            hashMap[in_order[i]] = i;
            inorder.push_back(i);
        }

        int preOrderIndex = 0;

        return buildBT(preOrderIndex, 0, in_order.size()-1, hashMap);
    }

    TreeNode* buildBT(int& preOrderIndex, int inOrderStart, int inOrderEnd, unordered_map<int, int>& hashMap) {
        // baseCase
        if (inOrderStart>inOrderEnd) return nullptr;

        // identify root
        int rootValue = preorder[preOrderIndex++];
        TreeNode* root = new TreeNode(rootValue);

        // evaluate inOrderIndex
        int inOrderIndex = hashMap[rootValue];

        // join root->left and root->right
        root->left = buildBT(preOrderIndex, inOrderStart, inOrderIndex-1, hashMap);
        root->right = buildBT(preOrderIndex, inOrderIndex+1, inOrderEnd, hashMap);

        // return root
        return root;
    }
};