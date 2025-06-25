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
 //dfs and dp
 //dfs to explore and dp to decide if to profitable to rob node or not.
class Solution {
public:
    int rob(TreeNode* root) {
        auto [with_rob,without_rob] = dfs(root);
        return max(with_rob,without_rob);
    }
    
    pair<int,int> dfs(TreeNode* root){
        //base case
        if(!root){
            return {0,0};
        }

        //postorder traversal
        auto [left_with_rob,left_without_rob] = dfs(root->left);
        auto [right_with_rob,right_without_rob] = dfs(root->right);

        //rob curr node, then cannot rob children
        int with_rob = root->val + left_without_rob+right_without_rob;
        //not rob curr node, rob max of rob and not rob for each of its children
        int without_rob = max(left_with_rob,left_without_rob) + max(right_with_rob,right_without_rob);

        return {with_rob,without_rob};
    }
};//O(N) where N is no of nodes coz dfs called once per node and 
//O(H) where H height of bin tree  - O(N) for worst case and O(logN) for best