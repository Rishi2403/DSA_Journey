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

void levelorderTraversal(Node* rootNode){

    //base case 
    if (rootNode==NULL){
        return;
    }
    queue<Node*> q;
    q.push(rootNode);

    while(!q.empty()){

        int nodesAtCurrentlevel=q.size();
        while(nodesAtCurrentlevel--){

            Node* currnode=q.front();
            q.pop();
            cout<<currnode->value<<" ";

            if(currnode->left!=NULL){
                q.push(currnode->left);
            }
            if(currnode->right!=NULL){
                q.push(currnode->right);
            }

        }
        cout<<endl;

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

    levelorderTraversal(root);

   
    return 0;
}