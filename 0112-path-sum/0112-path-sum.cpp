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
    bool hasPathSum(TreeNode* root, int targetSum) {
        // Base case: If the node is null, no path exists
        if (root == nullptr) {
            return false;
        }
        
        // If it is a leaf node, check if its value equals the remaining targetSum
        if (root->left == nullptr && root->right == nullptr) {
            return root->val == targetSum;
        }
        
        // Subtract the current node's value from targetSum and recurse down both subtrees
        int remainingSum = targetSum - root->val;
        return hasPathSum(root->left, remainingSum) || hasPathSum(root->right, remainingSum);
    }
};