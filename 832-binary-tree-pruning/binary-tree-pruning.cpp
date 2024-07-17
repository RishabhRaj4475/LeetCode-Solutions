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

    TreeNode* isOnePresent(TreeNode* root){
        if( root == NULL) return NULL;

        root->left = isOnePresent(root->left);
        root->right = isOnePresent(root->right);

        if(root->right == NULL and root->left == NULL and root->val != 1) return NULL;

        return root;
    }
    TreeNode* pruneTree(TreeNode* root) {

        if( root == NULL) return nullptr;

        root->left = pruneTree(root->left);
        root->right = pruneTree(root->right);

        if(root->left == NULL and root->right == NULL and root->val == 0) return NULL;

        return root;
        
    }
};