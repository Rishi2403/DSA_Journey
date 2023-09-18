#include<iostream>
#include<queue>
using namespace std;

class Node{
    public:

    int value;
    Node* left;
    Node* right;

    Node(int v){
        value=v;
        left=right=NULL;
    }
};

vector<int> rightviewbinarytree(Node* root){

    vector<int> ans,v;
    //base case 
    if (root==NULL){
        return ans;
    }
    queue<Node*> q;
    q.push(root);

    while(!q.empty()){

    int nodesAtCurrentlevel=q.size();
        while(nodesAtCurrentlevel){

            Node* currnode=q.front();
            q.pop();
            if(nodesAtCurrentlevel==1){
                ans.push_back(currnode->value);
            }

            if(currnode->left!=NULL){
                q.push(currnode->left);
            }
            if(currnode->right!=NULL){
                q.push(currnode->right);
            }
            nodesAtCurrentlevel--;
        }
    }
}

int main()
{
    Node* root=new Node(2);
    root->left=new Node(4);
    root->right=new Node(10);

    root->left->left=new Node(6);
    root->left->right=new Node(5);

    root->right->right=new Node(11);

    vector<int> ans=rightviewbinarytree(root);
    for(auto i:ans){
        cout<<i<<" ";
    }

   
    return 0;
}