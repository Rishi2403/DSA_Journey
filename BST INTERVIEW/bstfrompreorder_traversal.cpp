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

    TreeNode* bstFromPreOrderHelper(vector<int> & preorder , int& index , int upperbound){

        if(index >= preorder.size()){
            return NULL;
        }
        if (preorder[index] >= upperbound ){
            return NULL;
        }

        TreeNode* root= new TreeNode(preorder[index]);
        index++;
        root->left= bstFromPreOrderHelper(preorder , index , root->val);
        root->right=bstFromPreOrderHelper(preorder , index , upperbound);

        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        
        int index =0;
        return bstFromPreOrderHelper(preorder , index , INT_MAX);
    }
};