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

Node* mergesortlinkedlist(Node* &head1,Node* &head2)
{
    Node* dummyhead=new Node(-1);

    Node* ptr1=head1;
    Node* ptr2=head2;
    Node* ptr3=dummyhead;

    while(ptr1!=NULL && ptr2!=NULL)
    {
        if(ptr1->val < ptr2->val)
        {
            ptr3->next=ptr1;
            ptr1=ptr1->next;
        }
        else if(ptr1->val > ptr2->val)
        {
            ptr3->next=ptr2;
            ptr2=ptr2->next;
        }
        ptr3=ptr3->next;
    }
    if(ptr1!=NULL)
    {
        while (ptr1!=NULL)
        {
            ptr3->next=ptr1;
            ptr1=ptr1->next;
            ptr3=ptr3->next;
        }
        
    }
    if(ptr2!=NULL)
    {
        while (ptr2!=NULL)
        {
            ptr3->next=ptr2;
            ptr2=ptr2->next;
            ptr3=ptr3->next;
        }
        
    }
    return (dummyhead->next);
}


int main() {
    int x;
    LinkedList ll;
    // for (int i=0;i<5;i++)
    // {   cin>>x;
    //     ll.insertAtTail(x);
    // }
    //ll.Display();
    //reverseorder(ll.head);
    //ll.Display();
    ll.insertAtTail(1);
    ll.insertAtTail(4);
    ll.insertAtTail(5);
    ll.Display();
    
    LinkedList ll2;

    ll2.insertAtTail(2);
    ll2.insertAtTail(3);
    ll2.Display();
    
    LinkedList ll3;
    ll3.head=mergesortlinkedlist(ll.head,ll2.head);
    ll3.Display();


return 0;
}