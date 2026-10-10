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
    int minDepth(TreeNode* root) {
        // Base case: If the tree is empty, the depth is 0
        if (root == nullptr) {
            return 0;
        }
        
        // If the left subtree is empty, we must find the min depth in the right subtree
        if (root->left == nullptr) {
            return minDepth(root->right) + 1;
        }
        
        // If the right subtree is empty, we must find the min depth in the left subtree
        if (root->right == nullptr) {
            return minDepth(root->left) + 1;
        }
        
        // If both children exist, take the minimum of both depths plus 1 for the current node
        return min(minDepth(root->left), minDepth(root->right)) + 1;
    }
};