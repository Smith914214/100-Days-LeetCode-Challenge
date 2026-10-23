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
private:
    bool validate(TreeNode* node, long long low, long long high) {
        // An empty tree is a valid BST
        if (node == nullptr) {
            return true;
        }
        
        // The current node's value must be strictly within the allowed range
        if (node->val <= low || node->val >= high) {
            return false;
        }
        
        // Recursively check left and right subtrees with updated bounds
        return validate(node->left, low, node->val) && 
               validate(node->right, node->val, high);
    }

public:
    bool isValidBST(TreeNode* root) {
        // Initialize the range with the absolute minimum and maximum values possible
        return validate(root, LLONG_MIN, LLONG_MAX);
    }
};