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

    bool findPath(TreeNode* root , int target , string &path){
        if( root == NULL) return false ;

        if( root->val == target) return true;

        path.push_back('L');
        if(findPath( root->left , target , path) == false)
        path.pop_back();
        else return true;

        path.push_back('R');
        if(findPath(root->right , target , path) == false)
        path.pop_back();
        else return true;

        return false;

    }

    string getDirections(TreeNode* root, int startValue, int destValue) {
        string rootToSrc = "" ;
        string rootToDst = "" ;
        
        findPath(root , startValue , rootToSrc);
        findPath(root , destValue , rootToDst);

        cout<<rootToSrc<<endl<<rootToDst<<endl;

        int i = 0 , j = 0;
        string result = "";

        while(i < rootToSrc.length() and j < rootToDst.length() and rootToSrc[i] == rootToDst[j]){
            i++;
            j++;
        }

        for( ; i < rootToSrc.length() ; i++) result.push_back('U');

        for( ; j < rootToDst.length() ; j++) result.push_back(rootToDst[j]);

        return result;
        
    }
};