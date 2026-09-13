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
    // Helper function to traverse the tree
    void traverse(TreeNode* root, vector<int>& result) {
        if (root == nullptr) return;
        
        traverse(root->left, result);  // Visit Left Subtree
        result.push_back(root->val);   // Visit Root
        traverse(root->right, result); // Visit Right Subtree
    }

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        traverse(root, result);
        return result;
    }
};