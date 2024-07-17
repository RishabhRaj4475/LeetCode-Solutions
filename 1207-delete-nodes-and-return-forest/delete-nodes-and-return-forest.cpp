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

    TreeNode* solve(TreeNode* root , unordered_set<int> st , vector<TreeNode*> &result){
        if(!root) return NULL;

        root->left = solve(root->left , st , result);
        root->right = solve(root->right , st , result);

        if(st.find(root->val) != st.end()){
            if(root->left != NULL) result.push_back(root->left);
            if(root->right != NULL) result.push_back(root->right);

            //delete root;
            return NULL;
        }
        return root;
    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {

        if(root == NULL) return {};
        unordered_set<int> st;
        for(auto x:to_delete) st.insert(x);

        vector<TreeNode*> result;
        solve(root , st , result);

        if(root != NULL and st.find(root->val) == st.end()) result.push_back(root);

        return result;
    }
};