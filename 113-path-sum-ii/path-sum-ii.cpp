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
    vector<vector<int>> res;

    void solve(vector<int> &path , TreeNode* root , int target , int curr){
        if(root == NULL) return;

        if(root->left == NULL and root->right == NULL and curr == target ){
            res.push_back(path);
            return;
        }

        if(root->left != NULL){
            path.push_back(root->left->val);
            solve(path , root->left , target , curr + root->left->val);
            path.pop_back();
        }

        if(root->right != NULL){
            path.push_back(root->right->val);
            solve(path , root->right , target , curr + root->right->val);
            path.pop_back();
        }

    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> path;

        if(root == NULL) return {};

        path.push_back(root->val);
        solve(path , root , targetSum , root->val);

        return res;
    }
};