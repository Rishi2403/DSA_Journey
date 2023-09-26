#include<vector>
#include<map>

  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
 
class Solution {
public:

    TreeNode* buildTreehelper(vector<int>& preorder,int prestart,int preend,        vector<int>& inorder,int instart, int inend, map<int,int>& imap){

        if(prestart>preend || instart>inend){
            return NULL;
        }
        TreeNode* rootNode=new TreeNode(preorder[prestart]);
        
        int inorderRootindex=imap[rootNode->val];
        int leftsubtreeEle=inorderRootindex-instart;

        rootNode->left=buildTreehelper(preorder,prestart+1,prestart+leftsubtreeEle,     inorder,instart,inorderRootindex-1,imap);
        
        rootNode->right=buildTreehelper(preorder,prestart+leftsubtreeEle+1,preend,inorder,inorderRootindex+1,inend,imap);

        return rootNode;
    }


    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        map<int,int> imap;
        for(int i=0;i<inorder.size()-1;i++){
            imap[inorder[i]]=i;
        }

        return buildTreehelper(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1,  imap);
    }
}