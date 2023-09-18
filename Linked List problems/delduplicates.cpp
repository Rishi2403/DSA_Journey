#include<iostream>
using namespace std;

class Node {
    public:
    int val;
    Node* next;

    Node(int data) {
        val=data;
        next=NULL;
    }

};

// class Node()
// {
//     public:                       
//         Node* next;
//         int val;
//         Node(int data)
//         {
//             next=NULL;
//             val=data;
//         }
// };
class LinkedList{

    public:
        Node* head;

        LinkedList()
        {
            head=NULL;
        }

        void insertAtTail(int val){
       
            Node* new_node= new Node(val);

            if(head==NULL){
                head=new_node;
                return;
            }
        Node* temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=new_node;

    }
    void Display(){
        
        Node* temp=head;
        while(temp!=NULL){
            cout<<temp->val<<"->";
            temp=temp->next;
        }cout<<"NULL"<<endl;

    }

};
void delduplicates(Node* &head)
{
    Node* curr_node=head;

    while(curr_node!=NULL)
    {
        while(curr_node->next &&curr_node->val==curr_node->next->val){
            //node deletion
            Node* temp=curr_node->next;//node to be deleted
            curr_node->next=curr_node->next->next;
            free(temp);
        }// loop will end when curr node and next node is different
        curr_node=curr_node->next;
    }
}

int main() {
    int x;
    LinkedList ll;
    while(x!=0)
    {   cin>>x;
        ll.insertAtTail(x);
    }
    ll.Display();
    delduplicates(ll.head);
    ll.Display();
    // ll.insertAtTail(1);
    // ll.insertAtTail(2);
    // ll.insertAtTail(2);
    // ll.insertAtTail(3);
    // ll.Display();
    // delduplicates(ll.head);
    // ll.Display();

return 0;
}