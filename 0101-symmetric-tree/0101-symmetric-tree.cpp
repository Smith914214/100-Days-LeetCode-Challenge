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
    bool isSymmetric(TreeNode* root) {
        // An empty tree is symmetric
        if (!root) return true;
        
        // Compare the left and right subtrees
        return isMirror(root->left, root->right);
    }

private:
    bool isMirror(TreeNode* t1, TreeNode* t2) {
        // If both nodes are null, they are symmetric
        if (!t1 && !t2) return true;
        
        // If only one node is null, they are not symmetric
        if (!t1 || !t2) return false;
        
        // Check if values match and subtrees are mirrored crosswise
        return (t1->val == t2->val) 
            && isMirror(t1->left, t2->right) 
            && isMirror(t1->right, t2->left);
    }
};