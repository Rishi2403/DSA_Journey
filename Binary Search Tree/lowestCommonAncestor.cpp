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

Node* lowestCommonAncestor(Node* root , Node* node1 , Node* node2){


    //base case

    if(root==NULL){
        return root;
    }
    if(root->val > node1->val && root->val >node2->val ){
        // lca will lie left sub tree
        return lowestCommonAncestor(root->left ,node1 , node2);
    }
       if(root->val < node1->val && root->val < node2->val ){
        // lca will lie right sub tree
        return lowestCommonAncestor(root->right ,node1 , node2);
    }
    
    // if root value lies between node1 and node2 value 
    // or if root value is not equal to any of root values
    return root;
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

    Node* node1=new Node(2);
    Node* node2=new Node(3);
    
    Node* temp =lowestCommonAncestor(bst1.root , node1 , node2);
    cout<< temp->val<<"\n";

    return 0;
}