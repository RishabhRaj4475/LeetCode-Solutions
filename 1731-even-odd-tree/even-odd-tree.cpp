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
    bool isEvenOddTree(TreeNode* root) {
        if (!root) return true;

        queue<TreeNode*> q;
        q.push(root);
        int level = 0;

        while (!q.empty()) {
            vector<int> curr;
            int n = q.size();

            for (int i = 0; i < n; ++i) {
                TreeNode* node = q.front();
                q.pop();

                // Check value conditions based on level parity
                if ((level % 2 == 0 && (i > 0 && node->val <= curr.back() || node->val % 2 == 0))
                    || (level % 2 == 1 && (i > 0 && node->val >= curr.back() || node->val % 2 == 1))) {
                    return false;
                }

                curr.push_back(node->val);

                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }

            ++level;
        }

        return true;
    }
};