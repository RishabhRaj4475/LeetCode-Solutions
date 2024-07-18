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
public:
    int countPairs(TreeNode* root, int K) {
        int result = 0;
        // Call DFS helper function and pass the result by reference
        dfs(root, K, result);
        return result;
    }

private:
    // DFS function that returns a vector of distances of leaf nodes
    vector<int> dfs(TreeNode* node, int K, int& result) {
        if (!node) return {};

        // If it's a leaf node, return a vector with a single element 1
        if (!node->left && !node->right) {
            return {1};
        }

        // Get distances from left and right subtrees
        vector<int> leftDistances = dfs(node->left, K, result);
        vector<int> rightDistances = dfs(node->right, K, result);

        // Count valid pairs between left and right subtrees
        for (int ld : leftDistances) {
            for (int rd : rightDistances) {
                if (ld + rd <= K) {
                    result++;
                }
            }
        }

        // Prepare and return the updated distance information
        vector<int> distances;
        for (int ld : leftDistances) {
            distances.push_back(ld + 1);
        }
        for (int rd : rightDistances) {
            distances.push_back(rd + 1);
        }

        return distances;        
    }
};