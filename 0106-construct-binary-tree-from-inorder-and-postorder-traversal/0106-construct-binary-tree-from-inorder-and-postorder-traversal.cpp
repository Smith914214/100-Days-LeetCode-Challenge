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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        // Start from the last element of postorder (the root of the whole tree)
        int postIdx = postorder.size() - 1;
        
        // Map to store values and their corresponding indices in the inorder traversal
        unordered_map<int, int> inMap;
        for (int i = 0; i < inorder.size(); i++) {
            inMap[inorder[i]] = i;
        }
        
        return build(inorder, postorder, postIdx, inMap, 0, inorder.size() - 1);
    }

private:
    TreeNode* build(vector<int>& inorder, vector<int>& postorder, int& postIdx, 
                    unordered_map<int, int>& inMap, int inStart, int inEnd) {
        // Base case: if the range is invalid, there are no nodes to construct
        if (inStart > inEnd) return nullptr;

        // The current element in postorder is the root node
        int rootVal = postorder[postIdx];
        TreeNode* root = new TreeNode(rootVal);
        postIdx--; // Move to the next root element from the back

        // Find the index of this root in the inorder traversal
        int rootIdx = inMap[rootVal];

        // Crucial: Build the RIGHT subtree first because postorder is processed from right to left
        root->right = build(inorder, postorder, postIdx, inMap, rootIdx + 1, inEnd);
        root->left = build(inorder, postorder, postIdx, inMap, inStart, rootIdx - 1);

        return root;
    }
};