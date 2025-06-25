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
    vector<vector<int>> ans;

    void solve(TreeNode* root, vector<int> curr, int targetSum){
        if(!root) return;

        curr.push_back(root->val);
        targetSum -=root->val;

        if(!root->left && !root->right){
            if(targetSum == 0){
                ans.push_back(curr);
            }
        }

        solve(root->left, curr, targetSum);
        solve(root->right, curr, targetSum);

    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> curr;
        solve(root, curr, targetSum);
        return ans;
    }
};