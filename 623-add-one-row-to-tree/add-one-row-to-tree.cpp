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
int value;
    void solve(TreeNode* root , int depth , int h){
        if( root == NULL) return ;

        if( h == depth - 1){
            TreeNode* prevL = root->left , *prevR = root->right;
            root->left = new TreeNode(value);
            root->right = new TreeNode(value);
            root->left->left = prevL;
            root->right->right = prevR;
        }

        solve(root->left , depth , h + 1);
        solve(root->right , depth , h + 1);

    }
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        value = val;
        if (depth == 1) {
            TreeNode* newRoot = new TreeNode(val);
            newRoot->left = root;
            return newRoot;
        }
        solve(root , depth - 1 , 0);
        return root;
    }
};