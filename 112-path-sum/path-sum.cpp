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
    bool solve(TreeNode* root , int target , int curr){
        if(root == NULL) return false;

        curr += root->val;

        if(root->left == NULL and root->right == NULL ){
            return curr == target;
        }

        return solve(root->left , target , curr) or solve(root->right , target , curr);
    }
    bool hasPathSum(TreeNode* root, int targetSum) {

        if(root == NULL) return false;
        return solve(root , targetSum , 0);
    }
};