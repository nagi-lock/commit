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
    void dfs(TreeNode* node,vector<int>&path,int target,vector<vector<int>>&res){
        if(!node)return;
        target-=node->val;
        path.push_back(node->val);
        if(!node->left&&!node->right&&target==0){
            res.push_back(path);
        }else{
        dfs(node->left,path,target,res);
        dfs(node->right,path,target,res);
        }
        path.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>>res;
        vector<int>path;
        dfs(root,path,targetSum,res);
        return res;
    }
};