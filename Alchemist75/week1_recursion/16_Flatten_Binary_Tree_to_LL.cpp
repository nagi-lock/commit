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
 //graph->tree->dfs
 //preorder is Root-left-right
 //we need to move left nodes to right and make left null
class Solution {
public:
    void flatten(TreeNode* root) {
        //process all nodes.
        while(root){
            if(root->left){
                ///if left subtree exists
                //find rightmost node
                //save this node
                TreeNode* rightmost = root->left;
                while(rightmost->right){
                    rightmost = rightmost->right;
                }

                //save right subtree of curr node 
                //attach right subtree of curr node to rightmost node
                rightmost->right= root->right;

                //move left subtree to right-flattening
                root->right=root->left;

                //set left node to null , after moving
                root->left=nullptr;
            }
            root=root->right;
        }
    }
};//o(N) and O(H)