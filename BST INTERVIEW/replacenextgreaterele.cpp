#include<iostream>
#include<vector>
using namespace std;


class TreeNode{
    public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int v){
        val=v;
        left=right=NULL;
    }
};

TreeNode* insertNode(TreeNode* root , int element , int& successor){

    if(root==NULL){
        return new TreeNode(element);
    }
    if(element<root->val){
        successor=root->val;
        root->left=insertNode(root->left , element , successor);
    }
    else if(element>root->val){
        root->right=insertNode(root->right , element , successor);
    }

    return root;

}
void replacewithGreatestElement(vector <int> &v){

    TreeNode* root=NULL;

    for(int i=v.size()-1 ; i>=0 ;i--){
        int successor=-1;
        root=insertNode(root , v[i] , successor);
        v[i]=successor;
    }
}

int main()
{
    cout<<"Enter input"<<"\n";
    int n; cin>> n;

    vector<int> v(n);

    for(int i=0;i<n;i++){
        cin>>v[i];
    }

    replacewithGreatestElement(v);
    for(int i=0;i<n;i++){
        cout<<v[i]<<" ";
    }cout<<"\n";
    return 0;
}