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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        //map of inorder
        map<int,int> inorderMap;
        for(int i = 0;i<inorder.size();i++){
            inorderMap[inorder[i]] = i;
        }

        TreeNode* root = helper(preorder,0,preorder.size()-1,
        inorder,0,inorder.size()-1,inorderMap
        );

        return root;
    }


    TreeNode* helper(
        vector<int>& preorder,int preStart,int preEnd,
        vector<int>& inorder,int inStart,int inEnd,map<int,int>& inorderMap
    ){
        //base case
        if(preStart>preEnd || inStart>inEnd){
            return nullptr;
        }
        //make new root
        TreeNode* root = new TreeNode(preorder[preStart]);

        int inorderRoot = inorderMap[root->val];
        int numsLeft = inorderRoot-inStart;

        root->left = helper(
            preorder,preStart+1,preStart+numsLeft,
            inorder,inStart,inorderRoot-1,inorderMap
        );

        root->right = helper(
            preorder,preStart+numsLeft+1,preEnd,
            inorder,inorderRoot+1,inEnd,inorderMap
        );

        return root;
    }
};//O(N) and O(N)