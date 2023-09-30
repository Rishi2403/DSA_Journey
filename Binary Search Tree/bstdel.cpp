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

Node* largestNodeBST(Node* &root){
    Node* curr=root;

    while (curr and curr->right!=NULL)
    {
        curr=curr->right;
    }
    return curr;
}

Node* delNode(Node* &root , int val){
    //base case
    if(root==NULL){
        return root;
    }

    if (root->val > val){
        root->left= delNode(root->left, val);
    }
    else if (root->val < val){
        root->right= delNode(root->right, val);
    }
    else{
        //root is node to be deleted

        //if it has no child
        if (root->left==NULL and root->right==NULL){
            free(root);
            return NULL;
        }
        // node has one child
        else if(root->left==NULL ){
            Node* temp=root->right;
            free(root);
            return temp;
        }
         else if(root->right==NULL ){
            Node* temp=root->left;
            free(root);
            return temp;
        }
        // has 2 child nodes
        else{
            Node* justSmallerNode=largestNodeBST(root->left);
            root->val=justSmallerNode->val;
            root->left=delNode(root->left , justSmallerNode->val);
        }
    }
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

    inorderTraversal(bst1.root);

    cout<<endl;

    bst1.root=delNode(bst1.root ,2);

    inorderTraversal(bst1.root);
    return 0;
}