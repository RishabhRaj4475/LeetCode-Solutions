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
    string result = "";
    void solve(TreeNode* root , string curr){
        if(root == NULL) return;

        curr += char(root->val + 'a');
        
        if (root->left == NULL && root->right == NULL) {
            reverse(curr.begin(), curr.end());
            if (result == "" || curr < result) {
                result = curr;
            }
            reverse(curr.begin(), curr.end());
            return;
        }

        solve(root->left, curr);
        solve(root->right, curr);
        
    }
    string smallestFromLeaf(TreeNode* root) {
        string curr = "";
        solve(root , curr);
        return result;
    }
};