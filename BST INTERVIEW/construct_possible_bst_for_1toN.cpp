
 // Definition for a binary tree node.
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };

//Leetcode solution
class Solution {
public:

    vector<TreeNode*> generateTreesHelper(int start , int end){

        vector<TreeNode*> treesList;
        //base case 

        if(start > end){
            treesList.push_back(NULL);
            return treesList;
        }
        for(int i =start ;i<=end ; i++){

            //recursive case
            vector<TreeNode*> leftsubtrees=generateTreesHelper(start , i-1);
             vector<TreeNode*> rightsubtrees=generateTreesHelper(i+1 , end);

             for(TreeNode* leftsubtree :leftsubtrees){
                 for(TreeNode* rightsubtree :rightsubtrees){
                     TreeNode* rootNode=new TreeNode(i);
                     rootNode->left=leftsubtree;
                     rootNode->right=rightsubtree;
                     treesList.push_back(rootNode);
                 }
             }
        }
        return treesList;
    } 

    vector<TreeNode*> generateTrees(int n) {
        
        return generateTreesHelper(1 , n);
    }
};