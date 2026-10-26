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
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> allPaths;
        vector<int> currentPath;
        dfs(root, targetSum, currentPath, allPaths);
        return allPaths;
    }

    private:
           void dfs(TreeNode* node, int remainingSum, vector<int>& currentPath, vector<vector<int>>& allPaths) {
            if(!node) return;

            currentPath.push_back(node->val);

            if(!node->left && !node->right && remainingSum == node->val) {
                allPaths.push_back(currentPath);
            } else {
                dfs(node->left, remainingSum - node->val, currentPath, allPaths);
                dfs(node->right, remainingSum - node->val, currentPath, allPaths);
            }
            currentPath.pop_back();
           }
};