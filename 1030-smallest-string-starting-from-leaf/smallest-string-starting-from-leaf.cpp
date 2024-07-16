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
    string smallestFromLeaf(TreeNode* root) {
        if (!root) return "";

        using NodePathPair = pair<TreeNode*, string>;
        queue<NodePathPair> q;
        q.push({root, string(1, char(root->val + 'a'))});  // Initialize with the node's character

        string result = "~";  // Initializing with a character greater than any lowercase letter

        while (!q.empty()) {
            auto [node, path] = q.front();
            q.pop();

            if (!node->left && !node->right) {
                // Compare path directly with result
                if (path < result) {
                    result = path;
                }
            }

            if (node->left) {
                q.push({node->left, char(node->left->val + 'a') + path});
            }
            if (node->right) {
                q.push({node->right, char(node->right->val + 'a') + path});
            }
        }

        return result;
        
    }
};