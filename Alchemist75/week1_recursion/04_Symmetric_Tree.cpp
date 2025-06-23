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
        if(!root){
            return false;
        }
        return helper(root->left,root->right);//compare left half and right half
    }
    bool helper(TreeNode* p,TreeNode* q){
        //base cases are cases where comparison happens once and leaves.
        //these are cases when condition has to be false(i.e tree is NOT symmetric)
        if(p==nullptr && q==nullptr){
            return true;
        }
        
        if(p==nullptr || q==nullptr || p->val!=q->val ){
            return false;
        }
        //recursive cases are cases where condition needs to be true
        //since only when condition true, will recursion proceed to next level
        //in this case both parts have to be true for it to be a symmetric tree or for recursion to proceed further.
        return helper(p->left,q->right) && helper(p->right,q->left);
    }
};