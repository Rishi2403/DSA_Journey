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

int main()
{
    Node* root=new Node(2);
    root->left=new Node(3);
    root->right=new Node(4);

    cout<<"Root node "<<root->value <<"\n";
    cout<<"Left node "<<root->right->value <<"\n";
    cout<<"Right node "<<root->left->value <<"\n";

    return 0;
}