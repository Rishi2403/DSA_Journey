#include<iostream>
using namespace std;

class Node{
    public:
    int val;
    Node* left;
    Node* right;

    Node(int v){
        val=v;
        left=right=NULL;
    }
};

class BST {
    public: 
    Node* root;

    BST(){
        root=NULL;
    }
};

void insertBST(Node* &root , int val){
    
    Node* newNode= new Node(val);
    if(root==NULL){
        root=newNode;
        return;
    }

    Node* current=root;
    while(true){
        if(current->val > val){
            if(current->left==NULL){
                current->left=newNode;
                return;
            }current=current->left;}
            else{
                  if(current->right==NULL){
                current->right=newNode;
                return;
            }
            current=current->right;
        }
    }

}

Node* insertBSTrecursive(Node* root , int val){

    // base case
    if(root==NULL){
        Node* newNode=new Node(val);
        return newNode;
    }
    // recursive case
    if(root->val > val){
        root->left=insertBSTrecursive(root->left , val);
    }
    else if (root->val < val){
        root->right=insertBSTrecursive(root->right,val);
    }
}
Node* removeLeafNodes(Node* root){
    //base case
    if(root==NULL){
        return root;
    }

    if(root->left==NULL && root->right==NULL){
        return NULL; // root is leaf node
    }

    //recursive case 
    root->left=removeLeafNodes(root->left);
    root->right=removeLeafNodes(root->right);

    return root;
}
void preorderTraversal(Node* root){

    if(root==NULL) return;

    cout<<root->val<<" ";
    preorderTraversal(root->left);    
    preorderTraversal(root->right);
}

int main()
{
    BST bst1;

    bst1.root=insertBSTrecursive(bst1.root,4);
    insertBSTrecursive(bst1.root,6);
    insertBSTrecursive(bst1.root,3);
    insertBSTrecursive(bst1.root,2);
    insertBSTrecursive(bst1.root,1);

    preorderTraversal(bst1.root);
    cout<<"\n";
    bst1.root=removeLeafNodes(bst1.root);
    preorderTraversal(bst1.root);
    cout<<"\n";
    return 0;
}