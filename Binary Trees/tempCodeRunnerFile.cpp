
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

int maxdepth(Node* rootNode){

    //base case 
    if (rootNode==NULL){
        return 0;
    }    
    
    int leftDepth=maxdepth(rootNode->left);
    cout<<leftDepth<<"\n";
    int rightDepth=maxdepth(rootNode->right);

    return (max(leftDepth,rightDepth)+1);
}