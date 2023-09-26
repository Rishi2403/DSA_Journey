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
TreeNode* constructTree(vector < int > & preorder, int preStart, int preEnd, vector 
 < int > & inorder, int inStart, int inEnd, map < int, int > & mp) {
  if (preStart > preEnd || inStart > inEnd) return NULL;

    TreeNode* rootNode = new TreeNode(preorder[preStart]);
    int rootinorderindex = mp[rootNode -> val];
    int leftsubtreeEle =rootinorderindex  - inStart;

    rootNode -> left = constructTree(preorder, preStart + 1, preStart + leftsubtreeEle,  inorder,
    inStart, rootinorderindex - 1, mp);
    rootNode -> right = constructTree(preorder, preStart + leftsubtreeEle + 1, preEnd, inorder, 
    rootinorderindex + 1, inEnd, mp);

      return rootNode;
}

TreeNode* buildTree(vector < int > & preorder, vector < int > & inorder) {
    int preStart = 0, preEnd = preorder.size() - 1;
    int inStart = 0, inEnd = inorder.size() - 1;

    map < int, int > mp;
    for (int i = inStart; i <= inEnd; i++) {
        mp[inorder[i]] = i;
    }

  return constructTree(preorder, preStart, preEnd, inorder, inStart, inEnd, mp);
}
};