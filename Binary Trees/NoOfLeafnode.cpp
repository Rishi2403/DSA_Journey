#include<iostream>
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

int LeafNodes(Node* rootNode){

    //base case 
    if (rootNode==NULL){
        return 0;
    }    
    if(rootNode->left==NULL && rootNode->right==NULL){
        return 1; //leaf node
    }

    //recursive case 
    int leftSubtreeleafNodes=LeafNodes(rootNode->left);
    int rightSubtreeleafNodes=LeafNodes(rootNode->right);

    return leftSubtreeleafNodes+rightSubtreeleafNodes;
}

int main()
{
    Node* root=new Node(2);
    root->left=new Node(4);
    root->right=new Node(10);

    root->left->left=new Node(6);
    root->left->right=new Node(5);

    root->right->right=new Node(11);

    cout<<LeafNodes(root);

   
    return 0;
}