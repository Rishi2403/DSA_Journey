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

Node* evenoddll(Node* &head)
{
    Node* odd_head=head;
    Node* even_head=head->next;
    Node* odd_ptr=odd_head;
    Node* even_ptr=even_head;

    while(even_ptr && even_ptr->next)
    {
        odd_ptr->next=odd_ptr->next->next;
        even_ptr->next=even_ptr->next->next;
        odd_ptr=odd_ptr->next;
        even_ptr=even_ptr->next;
    }
    odd_ptr->next=even_head;

    return odd_head;

}

int main() {
    int x;
    //cin>>x;
    LinkedList ll;
    // while(x!=0)
    // {   cin>>x;
    //     ll.insertAtTail(x);
    // }
    // ll.Display();
    // ll.head=(ll.head);
    // ll.Display();
    ll.insertAtTail(1);
    ll.insertAtTail(2);
    ll.insertAtTail(3);
    ll.insertAtTail(4);
    ll.insertAtTail(5);
    ll.insertAtTail(6);
    ll.Display();
    ll.head=evenoddll(ll.head);
    ll.Display();
    //ll.Display();

return 0;
}