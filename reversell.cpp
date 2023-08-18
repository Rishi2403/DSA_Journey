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
Node* revrsell(Node* &head)
{
    Node* curr_ptr=head;
    Node* prev_ptr=NULL;

    //curr_ptr will point to prev ptr
    //All three nodes wil get updated by one posn
    while(curr_ptr!=NULL){
        Node* next_ptr=curr_ptr->next;
        curr_ptr->next=prev_ptr;
        prev_ptr=curr_ptr;
        curr_ptr=next_ptr;        
    }
    //when this loop ends , prev_ptr will point to my last node which is new node
    Node* new_node=prev_ptr;
    return new_node;
}

Node* reversellrecursion(Node* & head)
{
    // base condition
    if(head==NULL || head->next==NULL) return head;

    //recursion case
    Node* new_head=reversellrecursion(head->next);
    head->next->next=head;
    head->next=NULL;// head is pointing to last node in reversed ll
    return new_head;
}

int main() {
    int x;
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
    ll.insertAtTail(2);
    ll.insertAtTail(3);
    ll.Display();
    ll.head=reversellrecursion(ll.head);
    ll.Display();

return 0;
}