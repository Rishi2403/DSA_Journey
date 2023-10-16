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
    bool isValidBSThelper(TreeNode* root , long min , long max){

        //base case
        if(root==NULL){
            return true;
        }
        
        //1. check range of BST
        if(root->val <= min || root->val >= max){
            return false;
        }
        //2 and 3 , check left & right subtree in BST
        return isValidBSThelper(root->left , min , root->val) //left subtree 
          && isValidBSThelper(root->right ,root->val , max);//right subtree
    }

    bool isValidBST(TreeNode* root) {
        
        return isValidBSThelper(root,LONG_MIN , LONG_MAX);

    }
};