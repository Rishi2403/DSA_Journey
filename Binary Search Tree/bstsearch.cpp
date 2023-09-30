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

bool searchTree(Node* &root , int val){

    if(root==NULL){
        return false;
    }
    if(root->val==val) 
    {
        return true;
    }
    if (root->val > val){
        return searchTree(root->left, val);
    }
    else if (root->val < val){
        return searchTree(root->right, val);
    }
}

void inorderTraversal(Node* root){

    if(root==NULL) return;

    inorderTraversal(root->left);
    cout<<root->val<<" ";
    inorderTraversal(root->right);
}

int main()
{
    BST bst1;

    bst1.root=insertBSTrecursive(bst1.root,4);
    insertBSTrecursive(bst1.root,6);
    insertBSTrecursive(bst1.root,3);
    insertBSTrecursive(bst1.root,2);
    insertBSTrecursive(bst1.root,1);

    inorderTraversal(bst1.root);

    cout<<endl;

    cout<<searchTree(bst1.root , 64);
    return 0;
}