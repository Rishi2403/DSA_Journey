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

bool Palindromell(Node* &head)
{
    //step 1 - find the middle element
    Node* slow_ptr=head;
    Node* fast_ptr=head;

    while(fast_ptr->next!=NULL and fast_ptr!=NULL)
    {
        slow_ptr=slow_ptr->next;
        fast_ptr=fast_ptr->next->next;
    }
    cout<<
    //return slow_ptr;

    //step 2- Break linked list into 2
    Node* curr_node=slow_ptr->next;
    Node* prev=slow_ptr;
    slow_ptr->next=NULL;

    //step 3- reverse the curr node
    while (curr_node)
    {
        Node* next_node=curr_node->next;
        curr_node->next=prev;
        prev=curr_node;
        curr_node=next_node;
    }

    //step 4-check if ll are equal 
    Node* ptr1=head;
    Node* ptr2=prev;

    while(ptr2)
    {
        if(ptr2->val != ptr1->val)
        {
            return false;
        }
        ptr1=ptr1->next;
        ptr2=ptr2->next;
    }
    return true;
    
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
    ll.insertAtTail(3);
    ll.insertAtTail(2);
    ll.insertAtTail(1);
    ll.Display();
    //ll.head=reversellrecursion(ll.head);
    x=Palindromell(ll.head);
    cout<<x;
    // ll.Display();

return 0;
}