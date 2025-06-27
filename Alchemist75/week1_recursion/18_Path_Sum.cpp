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
 /*
explore paths, dfs and then do backtracking.
currSum needs to be added first then you compare if equal to targetSum 
else you might miss valid path wher leaf = 2,currSum is 20 and targetSum is 22. Need to add it first before comparing currSum and targetSum
 */
class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> path;
        helper(root,targetSum,0,ans,path);
        return ans;
    }
    void helper(TreeNode* root,int targetSum,int currSum,
    vector<vector<int>>& ans,vector<int>& path
    ){
        //base case
        if (root == nullptr)
            return;

                   
        currSum += root->val;
        path.push_back(root->val);

        if(currSum==targetSum && root->left==nullptr && root->right==nullptr){
            ans.push_back(path);
        }

        
        helper(root->left,targetSum,currSum,ans,path);
        helper(root->right,targetSum,currSum,ans,path);

        //backtracking
        currSum -= root->val;
        path.pop_back();
    }
};//O(n) and O(nlogn)