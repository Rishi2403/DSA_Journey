#include<iostream>
#include<vector>
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

Node* sortedArrayToBST(vector<int> v, int start, int end){

    // base case 
    if(start>end){
        return NULL;
    }

    int mid =(start+end)/2;
    Node* root = new Node(v[mid]);
    //recursive case
    root->left=sortedArrayToBST(v,start ,mid-1 ); // recursively creating left subtree from left half 
    root->right=sortedArrayToBST(v , mid+1 , end); // recursively creating right subtree from right half 

    return root;
}

void preOrder(Node* root){

    if(root==NULL) return;

    cout<<root->val<<" ";
    preOrder(root->left);    
    preOrder(root->right);
}

int main()
{
    BST bst1;

    int n;
    cin>>n;

    vector<int> v(n);
    for(int i =0;i<n;i++){
        cin>>v[i];
    }
    bst1.root =sortedArrayToBST(v,0,n-1);
    preOrder(bst1.root);
    return 0;
}