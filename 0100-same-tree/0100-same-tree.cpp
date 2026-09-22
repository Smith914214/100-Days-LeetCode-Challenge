/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // Base case: both nodes are null, so they are identical
        if (p == nullptr && q == nullptr) {
            return true;
        }
        
        // If only one node is null, or their values don't match, they aren't identical
        if (p == nullptr || q == nullptr || p->val != q->val) {
            return false;
        }
        
        // Recursively check left and right subtrees
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};