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

bool checkequallinkedlist(Node* head1, Node* head2)
{
    Node* ptr1=head1;
    Node* ptr2=head2;

    while(ptr1!=NULL && ptr2!=NULL)
    {
        if(ptr1->val!=ptr2->val)
        {
            return false;
        }
        ptr1=ptr1->next;
        ptr2=ptr2->next;
    }
    if (ptr1==NULL and ptr2==NULL)
    {
        return true;
    }
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
    ll.insertAtTail(3);
    ll.insertAtTail(4);
    ll.Display();
    
    LinkedList l2;
    l2.insertAtTail(1);
    l2.insertAtTail(2);
    l2.insertAtTail(3);
    l2.insertAtTail(4);
    l2.Display();
    int z=checkequallinkedlist(ll.head,l2.head);
    if(z==1){
        cout<<"EQUAL"<<endl;
    }
    else{
        cout<<"UNEQUAL"<<endl;
    }
    

return 0;
}