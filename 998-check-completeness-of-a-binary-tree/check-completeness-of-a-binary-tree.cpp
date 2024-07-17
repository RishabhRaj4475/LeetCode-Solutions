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
    int countNodes(TreeNode* root){
        if(root == NULL) return 0;

        return 1 + countNodes(root->left) + countNodes(root->right);
    }
public:
    bool solve(TreeNode* root , int index , int cnt){
        if(root == NULL) return true;

        if(index > cnt) return false;

        return solve(root->left , index*2 , cnt) and solve(root->right , index*2 + 1 , cnt);

    }
    bool isCompleteTree(TreeNode* root) {
        if( root == NULL) return true;

        int cnt = countNodes(root);

        return solve(root , 1 ,cnt);
    }
};