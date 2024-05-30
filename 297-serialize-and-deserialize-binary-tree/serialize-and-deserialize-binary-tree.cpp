/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string result;
        serializeHelper(root, result);
        return result;
    }
    void serializeHelper(TreeNode* node, string& result) {
        // basecase
        if (!node) {
            result+="#,";
            return;
        }

        result += to_string(node->val) + ",";
        serializeHelper(node->left, result);
        serializeHelper(node->right, result);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<string> dataStrArr = split(data, ',');
        int i = 0;
        return deserializeHelper(dataStrArr, i);
    }
    TreeNode* deserializeHelper(vector<string>& dataStrArr, int& i) {
        if (dataStrArr[i] == "#") {
            i++;
            return nullptr;
        }
        TreeNode* node = new TreeNode(stoi(dataStrArr[i++]));
        node->left = deserializeHelper(dataStrArr, i);
        node->right = deserializeHelper(dataStrArr, i);

        return node;
    }
    vector<string> split(string data, char limiter) {
        string element;
        vector<string> result;
        for (int i=0; i<data.size(); i++) {
            if (data[i] == limiter) {
                result.push_back(element);
                element = "";
            } else {
                element+=data[i];
            }
        }

        return result;

    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));