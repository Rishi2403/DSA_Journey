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
    
    int calculateTime(TreeNode* startNode , unordered_map<TreeNode*,TreeNode*> &parent){
        unordered_set<TreeNode*> infected;
        queue<TreeNode*> q;
        q.push(startNode);
        infected.insert(startNode);
        int time=0;
        while(!q.empty()){
            int currLevelNodes=q.size();
            bool infectFlag=false;
            while(currLevelNodes--){

                TreeNode* currNode=q.front();
                q.pop();

                if(currNode->left && !infected.count(currNode->left)){
                   infectFlag=true; 
                   infected.insert(currNode->left);
                   q.push(currNode->left);
                }
                
                if(currNode->right && !infected.count(currNode->right)){
                   infectFlag=true; 
                   infected.insert(currNode->right);
                   q.push(currNode->right);
                }
                if(parent[currNode] && !infected.count(parent[currNode])){
                   infectFlag=true; 
                   infected.insert(parent[currNode]);
                   q.push(parent[currNode]);
                }
            }
            if(infectFlag) time++;
        }
        return time;
    }

    TreeNode* makeParent(TreeNode* root , unordered_map<TreeNode*, TreeNode*> &parent , int start ){
        queue<TreeNode*> q;
        q.push(root);
        TreeNode* startNode;
        while(!q.empty()){

            TreeNode* currNode=q.front();
            q.pop();
            if(currNode->val==start){
                startNode=currNode;
            }
            if(currNode->left){
                parent[currNode->left]=currNode;
                q.push(currNode->left);
            }
            if(currNode->right){
                parent[currNode->right]=currNode;
                q.push(currNode->right);
            }
        }
        return startNode;
    }
    int amountOfTime(TreeNode* root, int start) {

        unordered_map<TreeNode*, TreeNode*> parent;
        TreeNode* startNode=makeParent(root, parent , start);
        return calculateTime(startNode , parent);
        
    }
};