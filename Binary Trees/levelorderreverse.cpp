#include<iostream>
#include<queue>
#include<stack>
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

vector<int> levelorderreverseTraversal(Node* rootNode){

    vector<int> ans;
    //base case 
    if (rootNode==NULL){
        return ans;
    }
    queue<Node*> q;
    stack<Node*> s;
    q.push(rootNode);

    while(!q.empty()){

        int nodesAtCurrentlevel=q.size();
        while(nodesAtCurrentlevel--){

            Node* currnode=q.front();
            q.pop();
            s.push(currnode);
            

            if(currnode->right!=NULL){
                q.push(currnode->right);
            }
            if(currnode->left!=NULL){
                q.push(currnode->left);
            }

        }
    }

    while(!s.empty())
    {
        int temp=s.top()->value;
        ans.push_back(temp);
        s.pop();
    }
    return ans;
}

int main()
{
    Node* root=new Node(2);
    root->left=new Node(4);
    root->right=new Node(10);

    root->left->left=new Node(6);
    root->left->right=new Node(5);

    root->right->right=new Node(11);

    vector<int> ans=levelorderreverseTraversal(root);

    for(auto i:ans){
        cout<<i<<" ";
    }
   
    return 0;
}